#include <stdio.h>
#include "input.h"
#include "utils.h"

#pragma region Manager
// Add this function before the main function
void input_manager(Manager* manager) {
	printf("Enter manager ID: ");
	scanf_s("%d", &manager->id);

	printf("Enter manager name: ");
	scanf_s(" %[^\n]", manager->name, sizeof(manager->name)); // Read a string containing spaces

	printf("Enter manager position: ");
	scanf_s(" %[^\n]", manager->position, sizeof(manager->position));
}

int input_find_manager_id(void) {
	int manager_id;
	printf("Enter the manager ID to search for: ");
	scanf_s("%d", &manager_id);
	return manager_id;
}

int input_remove_manager_id(void) {
	int id;
	printf("Enter the ID of the manager to remove: ");
	scanf_s("%d", &id);
	return id;
}

void print_manager(Manager* manager) {
	if (manager == NULL) {
		printf("Manager not found.\n");
	}
	else {
		printf("Manager found:\n");
		printf_s("ID=%d, Name=%s, Position=%s\n",
			manager->id, manager->name, manager->position);
	}
}

#pragma endregion

#pragma region Client
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

int input_find_client_nif(void) {
	int nif;
	printf("Enter the NIF of the client to find: ");
	scanf_s("%d", &nif);
	return nif;
}

int input_remove_client_nif(void) {
	int nif;
	printf("Enter the NIF of the client to remove: ");
	scanf_s("%d", &nif);
	return nif;
}
#pragma endregion


#pragma region MobilityDevice

void input_mobility_device(MobilityDevice* mobility_device) {
	printf("Enter device ID: ");
	scanf_s("%d", &mobility_device->id);

	printf("Enter device type: ");
	scanf_s(" %[^\n]", mobility_device->type, sizeof(mobility_device->type)); // Read a string containing spaces

	printf("Enter device cost: ");
	scanf_s("%lf", &mobility_device->cost);

	printf("Enter device battery charge: ");
	scanf_s("%lf", &mobility_device->autonomy);

	printf("Enter device geocode: ");
	scanf_s(" %[^\n]", mobility_device->geocode, sizeof(mobility_device->geocode)); // Read a string containing spaces
}

int input_find_mobility_device_id(void) {
	int device_id;
	printf("Enter the ID of the mobility device to find: ");
	scanf_s("%d", &device_id);
	return device_id;
}

int input_remove_mobility_device_id(void) {
	int device_id;
	printf("Enter the ID of the mobility device to remove: ");
	scanf_s("%d", &device_id);
	return device_id;
}

char* input_geocode(void) {
	char* geocode_to_find = (char*)malloc_safe(30 * sizeof(char));
	printf("Enter the geocode: ");
	scanf_s("%s", geocode_to_find, 30);
	return geocode_to_find;
}
#pragma endregion


#pragma region Rental
void input_rental(Rental* rental) {
	printf("Enter rental ID: ");
	scanf_s("%d", &rental->id);
	printf("Enter client NIF: ");
	scanf_s("%d", &rental->client_nif);
	printf("Enter device ID: ");
	scanf_s("%d", &rental->device_id);
	printf("Enter rental duration in minutes: ");
	scanf_s("%d", &rental->rental_duration);
}

void print_rental(Rental* rental) {
	if (rental == NULL) {
		printf("Rental not found\n");
	}
	else {
		printf("Rental ID: %d, Client NIF: %d, Device ID: %d, Rental Duration: %d minutes\n",
			rental->id, rental->client_nif, rental->device_id, rental->rental_duration);
	}
}

#pragma endregion
