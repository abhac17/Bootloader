#ifndef THEME_H
#define THEME_H

#include "monitor.h"

enum themes {PINK_BLACK, GREEN_YELLOW, DEEPPINK_YELLOW};

typedef struct theme{
    color_t normal_text_color;
    color_t selected_text_color;
}theme_t;

// Write a single char to screen
void monitor_put_wtheme(char c, theme_t theme, int selected);

void monitor_clear_wtheme(theme_t theme);

// Write a null-terminated ASCII
// string to the screen
void monitor_write_wtheme(char *c, theme_t theme, int selected);
void monitor_write_dec_wtheme(u32int n, theme_t theme, int selected);

/* For writing with the current theme: */

// Write a single char to screen
void monitor_put_theme(char c, int selected);

// Set the current theme
void monitor_set_theme(theme_t theme);
void monitor_set_theme_name(enum themes theme);

// Write a null-terminated ASCII
// string to the screen
void monitor_write_theme(char *c, int selected);
void monitor_write_dec_theme(u32int n, int selected);

void monitor_clear_theme();

#endif
