#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <hangman_core.h>
#include <utils.h>
#include <banners.h>

HANGMAN_API void hgm_make_attempt(size_t* attempt_index_ptr,
                                  char* attempts)
{
    char attempt = '\0';
    printf("Insira uma letra: ");

    if (scanf("%c%*c", &attempt) != EOF)
        attempts[*attempt_index_ptr++] = (char) toupper((unsigned char) attempt);
}

HANGMAN_API bool hgm_was_hanged(size_t error_count)
{
	return error_count >= HGM_MAX_ATTEMPT_ERROR;
}

HANGMAN_API void hgm_handle_add_word()
{
    char option = '\0';
    char new_word[HGM_MAX_WORD_SIZE] = {0};

    printf("Você deseja adicionar uma nova palavra ao jogo? (S/N)\n");
	
    if (scanf("%c%*c", &option) != EOF)
    {
        option = (char) toupper((unsigned char) option);
        if (option == 'S')
        {
            printf("Qual a nova palavra: ");

            if (fgets(new_word, sizeof new_word, stdin))
            {
                // transforma a palavra toda em maiúsculas
                strupper(new_word);

                // abre o "banco de dados"
                FILE* fdout = fopen(HGM_DATABASE_NAME, "r+");
                
                if (!fdout)
                {
                    printf("Desculpe, banco de dados não disponivel!\n\n");
			        exit(EXIT_FAILURE);
                }

                if (!add_word_to_database(fdout, new_word))
                {
                    printf("Não foi possível adicionar a palavra ao banco de dados\n\n");
			        exit(EXIT_FAILURE);
                }

                fclose(fdout);
            }
        }
    }
}

void hgm_handle_attempt(const char* secret_word, 
                        size_t attempt_index, 
                        size_t error_count)
{
	draw_hangman(error_count);
    bool letter_found;

	for(size_t index = 0u; index < strlen(secret_word); ++index)
    {
		
		letter_found = hgm_check_attempt(secret_word[index], 
                                         attempt_index, 
                                         secret_word);

		if (letter_found)
			printf("%c ", secret_word[index]);
		else
			printf("_ ");
	}
    
	puts("");
}
HANGMAN_API void hgm_show_result(bool is_winner)
{
    if(acertou()){
        show_winner_banner();
    }
    else{
        show_defeat_banner();
    }
    hgm_play_again();
}

HANGMAN_API int hgm_scored(const char* secret_word) {
	for(int i = 0; i<strlen(secret_word); i++){
		int nao_completou_palavra = !hgm_handle_attempt(secret_word[i]);
		if(nao_completou_palavra)
			return false;
	}
	return true;
}

HANGMAN_API bool hgm_play_again(){
    char play_again;
    printf("Deseja jogar novamente?(S/N)");
    scanf("%c%*c", &play_again);
    play_again = (char) toupper((unsigned char) play_again);
    if (play_again == 'S') return true;
    else return false;
}