#include "theme.h"

void os_1() {
    monitor_set_theme_name(DEEPPINK_YELLOW);
    monitor_clear_theme();
    monitor_write_theme("Welcome to Aplenite OS!",0);
}