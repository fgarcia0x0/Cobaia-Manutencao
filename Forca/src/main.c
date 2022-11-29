#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include <hangman_core.h>
#include <banners.h>

#define MAX_ALPHABET_COUNT 26

int main(int argc, char* argv[])
{
    char* secret_word                 = NULL;
    size_t attempt_index              = 0;
    bool play_again                   = 0;
	bool play_continue                = true;
    char attempts[MAX_ALPHABET_COUNT] = {0};

    show_game_banner();

	do{
		secret_word     = choose_secret_word();
		attempt_index   = 0;

		do {
			system("clear");

            size_t error_count = hgm_handle_wrong_attempt(&attempt_index, 
                                                          secret_word, 
                                                          attempt_index);

			hgm_handle_attempt(secret_word, attempt_index, error_count);

			hgm_store_attempt(&attempt_index, attempts);

			play_continue = !hgm_check_word_complete(secret_word) && 
                            !hgm_was_hanged(error_count);

		}while(play_continue);

		play_again = hgm_play_again();

	}while (play_again);

	handle_add_word();

    return EXIT_SUCCESS;
}