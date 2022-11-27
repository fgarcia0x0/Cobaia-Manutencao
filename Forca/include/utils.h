#pragma once

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

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

static bool add_word_to_database(FILE* fdout, const char* word)
{
    size_t word_cnt = 0u;

    if (fscanf(fdout, "%zu", &word_cnt) != 1u)
        return false;

    word_cnt++;

	// Posicionar o ponteiro para o começo do arquivo novamente 
	fseek(fdout, 0L, SEEK_SET);

	// Escrever no arquivo a quantidade de palavras
	fprintf(fdout, "%zu", word_cnt);

	// Posicionar o ponteiro para o fim do arquivo
	fseek(fdout, 0L, SEEK_END);

	// Escrever a nova palavra no fim do arquivo
	fprintf(fdout,"\n%s", word);

    // forçamos o fluxo de saida
    fflush(fdout);
}
