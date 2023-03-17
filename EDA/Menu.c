#include <stdio.h>
#include "menu.h"

void display_menu() {
    printf("\nMENU:\n");
    printf("1. Add manager\n");
    printf("2. Add client\n");
    printf("3. Add mobility device\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

MenuOption get_menu_choice() {
    int choice;
    scanf_s("%d", &choice);
    return (MenuOption)choice;
}
