#pragma once

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>

#define HGM_MAX_LINE_SIZE (1024u)

/**
 * @brief 
 * 
 * @param fdout 
 * @param line_index 
 * @return char* 
 */
static inline char* read_line(FILE* fdout, size_t line_index)
{
    return NULL;
}

/**
 * @brief 
 * @details tem que retornar a palavra secreta alocada dinamicante
 * @return char* 
 */
static inline char* choose_secret_word()
{
    return NULL;
}

static bool add_word_to_database(FILE* fdout, const char word[static 1])
{
    static_assert(sizeof(size_t) == sizeof(uintptr_t));

    size_t word_cnt = 0u;
    if (fscanf(fdout, "%" SCNuPTR, &word_cnt) != 1u)
        return false;

    word_cnt++;

	// Posicionar o ponteiro para o começo do arquivo novamente 
	fseek(fdout, 0L, SEEK_SET);

	// Escrever no arquivo a quantidade de palavras
	fprintf(fdout, "%" PRIuPTR, word_cnt);

	// Posicionar o ponteiro para o fim do arquivo
	fseek(fdout, 0L, SEEK_END);

	// Escrever a nova palavra no fim do arquivo
	fprintf(fdout,"\n%s", word);

    // forçamos o fluxo de saida
    fflush(fdout);

    return true;
}

static inline void strupper(char input[static 1])
{
    for (; *input != '\0'; ++input)
        *input = (char) toupper((unsigned char) *input);
}
