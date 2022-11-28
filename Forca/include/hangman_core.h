#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "plataform.h"

#define HGM_MAX_ATTEMPT_ERROR (7u) 
#define HGM_MAX_WORD_SIZE (1024u)

/**
 * @brief Stores the user's attempt in the attempt list
 * 
 * @param attempt_index_ptr A pointer to the attempt index
 * @param attempts The attempt list
 */
HANGMAN_API void hgm_store_attempt(size_t* attempt_index_ptr,
                                   char attempts[static]);

/**
 * @brief 
 * 
 * @param letter
 * @param attempt_index
 * @param attempts
 *
 * @return bool
 */
HANGMAN_API bool hgm_check_attempt(char letter, 
                                   size_t attempt_index, 
                                   const char attempts[static 1]);

/**
 * @brief 
 * 
 * @param attempt_index_ptr 
 * @param secret_word 
 * @param attempt_list 
 * @return size_t 
 */
HANGMAN_API size_t hgm_handle_wrong_attempt(size_t* attempt_index_ptr,
                                            const char secret_word[static 1],
                                            const char attempts[static 1]);

/**
 * @brief Checks if the user lost the game (was hanged)
 * 
 * @param error_count 
 * @return true if was hanged
 * @return false if not was hanged
 */
HANGMAN_API bool hgm_was_hanged(size_t error_count);


/**
 * @brief 
 * 
 * @param secret_word
 * 
 * @return bool
 */
HANGMAN_API bool hgm_check_word_complete(const char secret_word[static 1]);

/**
 * @brief 
 * 
 * @param secret_word
 */
HANGMAN_API void hgm_handle_attempt(const char secret_word[static 1]);

/**
 * @brief 
 * 
 * @param is_winner 
 */
HANGMAN_API void hgm_show_result(bool is_winner);

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
HANGMAN_API bool hgm_play_again();

/**
 * @brief Handles adding a new word to the database
 */
HANGMAN_API void hgm_handle_add_word();