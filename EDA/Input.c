#include <stdio.h>
#include "input.h"

// Add this function before the main function
void input_manager(Manager* manager) {
    printf("Enter manager ID: ");
    scanf_s("%d", &manager->id);

    printf("Enter manager name: ");
    scanf_s(" %[^\n]", manager->name, sizeof(manager->name)); // Read a string containing spaces

    printf("Enter manager position: ");
    scanf_s(" %[^\n]", manager->position, sizeof(manager->position));
}

void input_client(Client* client) {
    printf("Enter client NIF: ");
    scanf_s("%d", &client->nif);

    printf("Enter client name: ");
    scanf_s(" %[^\n]", client->name, sizeof(client->name)); // Read a string containing spaces

    printf("Enter client email: ");
    scanf_s(" %[^\n]", client->address, sizeof(client->address));

    printf("Enter client balance: ");
    scanf_s("%lf", &client->balance);
}

void input_mobility_device(MobilityDevice* mobility_device) {
    printf("Enter device ID: ");
    scanf_s("%d", &mobility_device->id);

    printf("Enter device type: ");
    scanf_s(" %[^\n]", mobility_device->type, sizeof(mobility_device->type)); // Read a string containing spaces

    printf("Enter device cost: ");
    scanf_s("%lf", &mobility_device->cost);

    printf("Enter device battery charge: ");
    scanf_s("%lf", &mobility_device->battery_charge);

    printf("Enter device location: ");
    scanf_s(" %[^\n]", mobility_device->location, sizeof(mobility_device->location)); // Read a string containing spaces
}
