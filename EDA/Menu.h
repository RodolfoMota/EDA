#ifndef MENU_H
#define MENU_H

typedef enum {
    OPTION_ADD_MANAGER = 1,
    OPTION_FIND_MANAGER,
    OPTION_REMOVE_MANAGER,
    OPTION_UPDATE_MANAGER,
    OPTION_ADD_CLIENT,
    OPTION_FIND_CLIENT, 
    OPTION_REMOVE_CLIENT, 
    OPTION_UPDATE_CLIENT, 
    OPTION_ADD_MOBILITY_DEVICE,
    OPTION_FIND_MOBILITY_DEVICE, // Add this line
    OPTION_REMOVE_MOBILITY_DEVICE, // Add this line
    OPTION_UPDATE_MOBILITY_DEVICE, // Add this line
    OPTION_LIST_MOBILITY_DEVICES, // Add this line
    OPTION_EXIT = 0
} MenuOption;

void display_menu();
MenuOption get_menu_choice();

#endif // MENU_H
