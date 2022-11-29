#pragma once

#include <stdio.h>

#define PUPPET_BODY(err, num, body, space) \
        ((err) >= (num) ? body : space)

static inline void show_game_banner()
{
    static const char* s_banner = "\n\n"
                                  "*******************************\n"
                                  "**       Jogo da Forca       **\n"
                                  "*******************************\n";
    puts(s_banner);
}

static inline void draw_hangman(size_t error_count)
{
    printf( "  _______      \n"
            " |/      |     \n"
            " |      %c%c%c \n"
            " |      %c%c%c \n"
            " |       %c    \n"
            " |      %c %c  \n"
            " |             \n"
            "_|___          \n"
            "\n\n", 
            PUPPET_BODY(error_count, 1, '(', ' '), 
            PUPPET_BODY(error_count, 1, '_', ' '),
            PUPPET_BODY(error_count, 1, ')', ' '),
            PUPPET_BODY(error_count, 3, '\\', ' '),
            PUPPET_BODY(error_count, 2, '|', ' '),
            PUPPET_BODY(error_count, 4, '/', ' '),
            PUPPET_BODY(error_count, 2, '|', ' '),
            PUPPET_BODY(error_count, 5, '/', ' '),
            PUPPET_BODY(error_count, 6, '\\', ' '));
    
}

static inline void show_defeat_banner(const char* secret_word)
{
    printf( "\nGame Over!, você foi enforcado!\n"
	        "A palavra era **%s**           \n\n"
	        "    _______________              \n"
	        "   /               \\            \n" 
	        "  /                 \\           \n"
	        "//                   \\/\\       \n"
	        "\\|   XXXX     XXXX   | /        \n"
	        " |   XXXX     XXXX   |/          \n"
	        " |   XXX       XXX   |           \n"
	        " |                   |           \n"
	        " \\__      XXX      __/          \n"
	        "   |\\     XXX     /|            \n"
	        "   | |           | |             \n"
	        "   | I I I I I I I |             \n"
	        "   |  I I I I I I  |             \n"
	        "   \\_             _/            \n"
	        "     \\_         _/              \n"
	        "       \\_______/                \n", secret_word);
}

static inline void show_winner_banner(const char* secret_word)
{
    printf( "\nParabéns, você ganhou!\n\n"
		    "A palavra era **%s**\n\n"
	        "       ___________      \n"
	        "      '._==_==_=_.'     \n"
	        "      .-\\:      /-.    \n"
	        "     | (|:.     |) |    \n"
	        "      '-|:.     |-'     \n"
	        "        \\::.    /      \n"
	        "         '::. .'        \n"
	        "           ) (          \n"
	        "         _.' '._        \n"
	        "        '-------'       \n\n", secret_word);
}