#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "manager.h"

// Adds a new manager to the array of managers
void add_manager(Manager** managers, int* num_managers, Manager new_manager) {

	// Resize the managers array to accommodate the new manager
	*managers = (Manager*)realloc_safe(*managers, (*num_managers + 1) * sizeof(Manager));

	if (*managers == NULL) {
		// Handle the memory allocation failure, e.g., continue with reduced functionality
		return;
	}

	// Add the new manager to the array
	(*managers)[*num_managers] = new_manager;

	// Increment the number of managers
	(*num_managers)++;
}

// Removes a manager from the array of managers using their ID
void remove_manager(Manager** managers, int* num_managers, int id) {
	// Iterate through the managers array
	for (int i = 0; i < *num_managers; i++) {
		// If the manager's ID matches the provided ID
		if ((*managers)[i].id == id) {
			// Shift all managers to the right of the matched manager to the left
			for (int j = i; j < *num_managers - 1; j++) {
				(*managers)[j] = (*managers)[j + 1];
			}

			// Resize the managers array to remove the matched manager
			*managers = (Manager*)realloc_safe(*managers, (*num_managers - 1) * sizeof(Manager));

			if (*managers == NULL) {
				// Handle the memory allocation failure, e.g., continue with reduced functionality
				return;
			}

			// Decrement the number of managers
			(*num_managers)--;

			// Exit the loop
			break;
		}
	}
}

// Updates an existing manager in the array of managers
void update_manager(Manager* managers, int num_managers, Manager updated_manager
) {
	// Iterate through the managers array
	for (int i = 0; i < num_managers; i++) {
		// If the manager's ID matches the updated manager's ID
		if (managers[i].id == updated_manager.id) {
			// Update the manager with the new data
			managers[i] = updated_manager;

			// Exit the loop
			break;
		}
	}
}

// Finds a manager in the array of managers using their ID and returns a pointer to the manager
Manager* find_manager(Manager* managers, int num_managers, int id) {
	// Iterate through the managers array
	for (int i = 0; i < num_managers; i++) {
		// If the manager's ID matches the provided ID
		if (managers[i].id == id) {
			// Return a pointer to the matched manager
			return &managers[i];
		}
	}
	// If no manager is found, return NULL
	return NULL;
}


void view_rental_history(Rental* rentals, int num_rentals) {
	printf("\nRental History:\n");
	printf("ID | Client NIF | Device ID | Rental Duration (min)\n");
	for (int i = 0; i < num_rentals; i++) {
		printf("%d | %d | %d | %d\n", rentals[i].id, rentals[i].client_nif, rentals[i].device_id, rentals[i].rental_duration);
	}
}

void calculate_statistics(Rental* rentals, int num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices) {
	int total_rentals = num_rentals;
	int total_clients = num_clients;
	int total_devices = num_devices;
	int rented_devices = 0;

	for (int i = 0; i < num_devices; i++) {
		if (devices[i].is_rented) {
			rented_devices++;
		}
	}

	printf("\nStatistics:\n");
	printf("Total rentals: %d\n", total_rentals);
	printf("Total clients: %d\n", total_clients);
	printf("Total devices: %d\n", total_devices);
	printf("Rented devices: %d\n", rented_devices);
}

void validate_rental_data(Rental* rentals, int num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices) {
	printf("\nValidating rental data...\n");

	int invalid_rentals = 0;

	for (int i = 0; i < num_rentals; i++) {
		Rental* rental = &rentals[i];
		if (!validate_rental(clients, num_clients, devices, num_devices, rentals, num_rentals, rental)) {
			printf("Invalid rental: ID %d, Client NIF %d, Device ID %d\n", rental->id, rental->client_nif, rental->device_id);
			invalid_rentals++;
		}
	}

	if (invalid_rentals == 0) {
		printf("All rentals are valid.\n");
	}
	else {
		printf("%d invalid rentals found.\n", invalid_rentals);
	}
}
