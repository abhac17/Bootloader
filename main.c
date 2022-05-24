#include "monitor.h"
#include "idt_int.h"
#include "keyb.h"
#include "theme.h"
#include "apleniteos.h"
#include "initos.h"

#define MAX_MENU_ITEMS 3

void customize_screen() {

    int curr_sel_idx = 0;

    monitor_clear_theme();
    // Write out a sample string
    monitor_write_theme("\n   CUSTOMIZE\n", 0);
    monitor_write_theme("\n   Select Theme:\n\n", 0);
    monitor_write_theme("\n   Theme 1\n", 1);
    monitor_write_theme("\n   Theme 2\n", 0);
    monitor_write_theme("\n   Theme 3\n", 0);

    char c = get_key();

    while (c != '\n') {
        if (c == '\t') {
            curr_sel_idx = (curr_sel_idx + 1) % MAX_MENU_ITEMS;
        }
        monitor_clear_theme();
        // Write out a sample string
        monitor_write_theme("\n   CUSTOMIZE\n", 0);
        monitor_write_theme("\n   Select Theme:\n\n", 0);
        monitor_write_theme("\n   Theme 1\n", (curr_sel_idx == 0 ? 1 : 0));
        monitor_write_theme("\n   Theme 2\n", (curr_sel_idx == 1 ? 1 : 0));
        monitor_write_theme("\n   Theme 3", (curr_sel_idx == 2 ? 1 : 0));
        c = get_key();
    }

    switch (curr_sel_idx) {
        case 0:
            monitor_set_theme_name(PINK_BLACK);
            break;

        case 1:
            monitor_set_theme_name(GREEN_YELLOW);
            break;

        case 2:
            monitor_set_theme_name(DEEPPINK_YELLOW);
            break;

        default:
            break;
    }
}

void mulboot(void)
{
    idt_init();
    load_idt_entry(0x21, (unsigned long) keyboard_handler_int, 0x08, 0x8e);
    kb_init();

    monitor_set_theme_name(PINK_BLACK);

    int curr_sel_idx = 0;

main_screen:
    monitor_clear_theme();
    // Write out a sample string
    monitor_write_theme("\n   Welcome to Init Boot\n", 0);
    monitor_write_theme("\n   Select OS to boot\n\n", 0);
    monitor_write_theme("\n   Init OS\n", 1);
    monitor_write_theme("\n   Aplenite OS\n\n\n\n", 0);
    monitor_write_theme("\n   Customize", 0);

    char c = 'n';
    while (c != '\n') {
        if (c == '\t') {
            curr_sel_idx = (curr_sel_idx + 1) % MAX_MENU_ITEMS;
        }
        monitor_clear_theme();
        // Write out a sample string
        monitor_write_theme("\n   Welcome to Init Boot\n", 0);
        monitor_write_theme("\n   Select OS to boot\n\n", 0);
        monitor_write_theme("\n   Init OS\n", (curr_sel_idx == 0 ? 1 : 0));
        monitor_write_theme("\n   Aplenite OS\n\n\n\n", (curr_sel_idx == 1 ? 1 : 0));
        monitor_write_theme("\n   Customize", (curr_sel_idx == 2 ? 1 : 0));
        c = get_key();
        monitor_write_theme("ok", 0);
    }

    switch (curr_sel_idx) {
        case 0:
            os_0();
            break;

        case 1:
            os_1();
            break;

        case 2:
            customize_screen();
            goto main_screen;
            break;

        default:
            break;
    }

    while(1) __asm__("hlt\n\t");
}