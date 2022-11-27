#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "plataform.h"

/**
 * @brief 
 * 
 * @param attempt_index_ptr 
 */
HANGMAN_API void hgm_make_attempt(size_t* attempt_index_ptr);

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
                                   const char* attempts);

/**
 * @brief 
 * 
 * @param attempt_index_ptr 
 * @param secret_word 
 * @param attempt_list 
 * @return size_t 
 */
HANGMAN_API size_t hgm_handle_wrong_attempt(size_t* attempt_index_ptr,
                                            const char* secret_word,
                                            const char* attempt_list);

/**
 * @brief 
 * 
 * @param error_count 
 * @return true 
 * @return false 
 */
HANGMAN_API bool hgm_was_hanged(size_t error_count);

/**
 * @brief 
 * 
 * @param secret_word
 * 
 * @return bool
 */
HANGMAN_API bool hgm_check_word_complete(const char* secret_word);

/**
 * @brief 
 * 
 * @param secret_word
 */
HANGMAN_API void hgm_handle_attempt(const char* secret_word);

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
 * @brief 
 * 
 */
HANGMAN_API void hgm_handle_add_word();