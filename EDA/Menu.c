#include "menu.h"

void display_menu() {
    printf("\nMENU:\n");
    printf("%d - Add manager\n", OPTION_ADD_MANAGER);
    printf("%d - Find a manager\n", OPTION_FIND_MANAGER);
    printf("%d - Remove a manager\n", OPTION_REMOVE_MANAGER);
    printf("%d - Update a manager\n", OPTION_UPDATE_MANAGER);
    printf("%d - Add client\n", OPTION_ADD_CLIENT);
    printf("%d - Find a client\n", OPTION_FIND_CLIENT); 
    printf("%d - Remove a client\n", OPTION_REMOVE_CLIENT); 
    printf("%d - Update a client\n", OPTION_UPDATE_CLIENT); 
    printf("%d - Add mobility device\n", OPTION_ADD_MOBILITY_DEVICE);
    printf("%d - Find a mobility device\n", OPTION_FIND_MOBILITY_DEVICE); 
    printf("%d - Remove a mobility device\n", OPTION_REMOVE_MOBILITY_DEVICE); 
    printf("%d - Update a mobility device\n",  OPTION_UPDATE_MOBILITY_DEVICE);
    printf("%d - List all mobility devices\n", OPTION_LIST_MOBILITY_DEVICES);
    printf("%d - List mobility devices by descending autonomy\n", OPTION_LIST_DEVICES_BY_DESCENDING_AUTONOMY);
    printf("%d - List mobility devices by geocode\n", OPTION_LIST_DEVICES_BY_GEOCODE);
    printf("%d - Register rental\n", OPTION_REGISTER_RENTAL);
    printf("0.  Exit\n");
    printf("Enter your choice: ");
}

MenuOption get_menu_choice() {
    int choice;
    scanf_s("%d", &choice);
    return (MenuOption)choice;
}
