#ifndef MENU_H
#define MENU_H

typedef enum {
    OPTION_ADD_MANAGER = 1,
    OPTION_ADD_CLIENT = 2,
    OPTION_ADD_MOBILITY_DEVICE = 3,
    OPTION_EXIT = 0
} MenuOption;

void display_menu();
MenuOption get_menu_choice();

#endif // MENU_H
