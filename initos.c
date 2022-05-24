
#include "theme.h"

void os_0() {
    monitor_set_theme_name(GREEN_YELLOW);
    monitor_clear_theme();
    monitor_write_theme("Welcome to Init OS!",0);
}