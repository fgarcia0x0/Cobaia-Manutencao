#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "hangman_core.h"
#include "utils.h"

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
                FILE* fdout = fopen("forca.txt", "r+");
                
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