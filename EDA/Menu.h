// Menu.h
#ifndef MENU_H
#define MENU_H

/**
 * @file Menu.h
 * @brief Contains the menu options enumeration and menu-related functions.
 */

 /**
  * @brief The menu options enumeration.
  */
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
    OPTION_FIND_MOBILITY_DEVICE,
    OPTION_REMOVE_MOBILITY_DEVICE,
    OPTION_UPDATE_MOBILITY_DEVICE,
    OPTION_LIST_MOBILITY_DEVICES,
    OPTION_LIST_DEVICES_BY_DESCENDING_AUTONOMY,
    OPTION_LIST_DEVICES_BY_GEOCODE,
    OPTION_REGISTER_RENTAL,
    OPTION_MANAGER_DASHBOARD,
    OPTION_EXIT = 0
} MenuOption;

/**
 * @brief Displays the main menu options.
 */
void display_menu();

/**
 * @brief Gets the menu choice from the user.
 *
 * @return The chosen menu option.
 */
MenuOption get_menu_choice();

#endif // MENU_H
