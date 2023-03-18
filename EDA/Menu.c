#include "menu.h"

void display_menu() {
    printf("\nMENU:\n");
    printf("1.  Add manager\n");
    printf("2.  Find a manager\n");
    printf("3.  Remove a manager\n");
    printf("4.  Update a manager\n");
    printf("5.  Add client\n");
    printf("6.  Find a client\n"); 
    printf("7.  Remove a client\n"); 
    printf("8.  Update a client\n"); 
    printf("9.  Add mobility device\n");
    printf("10. Find a mobility device\n"); 
    printf("11. Remove a mobility device\n"); 
    printf("12. Update a mobility device\n");
    printf("13. List all mobility devices\n");
    printf("0.  Exit\n");
    printf("Enter your choice: ");
}

MenuOption get_menu_choice() {
    int choice;
    scanf_s("%d", &choice);
    return (MenuOption)choice;
}
