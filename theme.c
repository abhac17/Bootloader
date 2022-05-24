#include "theme.h"
#include "monitor.h"

#define MAX_THEMES 3

theme_t avail_themes[] = {
    {
        {13, 0},
        {12, 0}
    },
    {
        {2, 14},
        {3, 14}
    },
    {
        {5, 15},
        {13, 0}
    },
};

theme_t current_theme = {
        {13, 0},
        {12, 0}
    };
enum themes current_theme_idx = 0;

void monitor_put_wtheme(char c, theme_t theme, int selected) {
    if (selected) {
        monitor_put(c, theme.selected_text_color);
    }
    else {
        monitor_put(c, theme.normal_text_color);
    }
}

void monitor_clear_wtheme(theme_t theme) {
    monitor_clear_bg(theme.normal_text_color);
}

// Write a null-terminated ASCII
// string to the screen
void monitor_write_wtheme(char *c, theme_t theme, int selected) {
    if (selected) {
        monitor_write(c, theme.selected_text_color);
    }
    else {
        monitor_write(c, theme.normal_text_color);
    }
}

void monitor_write_dec_wtheme(u32int n, theme_t theme, int selected) {
    if (selected) {
        monitor_write_dec(n, theme.selected_text_color);
    }
    else {
        monitor_write_dec(n, theme.normal_text_color);
    }
}

/* For writing with the current theme: */

// Write a single char to screen
void monitor_put_theme(char c, int selected) {
    monitor_put_wtheme(c, current_theme, selected);
}

// Set the current theme
void monitor_set_theme(theme_t theme) {
    current_theme = theme;
}

void monitor_set_theme_name(enum themes theme) {
    current_theme = avail_themes[(int) theme];
    current_theme_idx = theme;
}

void monitor_write_theme(char *c, int selected) {
    monitor_write_wtheme(c, current_theme, selected);
}

void monitor_write_dec_theme(u32int n, int selected) {
    monitor_write_dec_wtheme(n, current_theme, selected);
}

void monitor_clear_theme(){
    monitor_clear_wtheme(current_theme);
}