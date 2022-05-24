/***************************************************/
// File: monitor.h - prototypes for screen
//                   functions (write, clear, etc.)
/***************************************************/

#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"
#include "colors.h"

// Write a single char to screen
void monitor_put(char c, color_t color);

// Clear the screen
void monitor_clear();
void monitor_clear_bg(color_t color);

// Write a null-terminated ASCII
// string to the screen
void monitor_write(char *c, color_t color);
void monitor_write_dec(u32int n, color_t color);

#endif
