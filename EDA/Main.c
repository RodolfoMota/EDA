#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "menu.h"
#include "input.h"

/**

@file main.c
@brief Main function with menu for managing rentals of mobility devices.
*/

//project /
//│
//├── Source Files /
//│   ├── main.c
//│   ├── client.c
//│   ├── manager.c
//│   ├── mobilitydevice.c
//│   └── utils.c
//│
//└── Header Files /
//├── client.h
//├── manager.h
//├── mobilitydevice.h
//└── utils.h


/**
@brief Initializes and loads the data from binary files, and initializes the files if they do not exist.
@param managers Pointer to an array of managers.
@param num_managers Pointer to the number of managers in the array.
@param clients Pointer to an array of clients.
@param num_clients Pointer to the number of clients in the array.
@param devices Pointer to an array of mobility devices.
@param num_devices Pointer to the number of mobility devices in the array.
@param rentals Pointer to an array of rentals.
@param num_rentals Pointer to the number of rentals in the array.
*/
void initialize_and_load_data(Manager** managers, int* num_managers, Client** clients, int* num_clients, MobilityDevice** devices, int* num_devices, Rental** rentals, int* num_rentals);

/**

@brief Main function with menu for managing rentals of mobility devices.

@return int Exit code.
*/
int main() {

	// Declare pointers for the arrays and their counts
	Manager* managers = NULL;
	Client* clients = NULL;
	MobilityDevice* devices = NULL;
	Rental* rentals = NULL;

	int num_managers, num_clients, num_rentals, num_devices = 0;


	// Initialize and load data
	initialize_and_load_data(&managers, &num_managers, &clients, &num_clients, &devices, &num_devices, &rentals, &num_rentals);


	MenuOption user_choice;
	do {
		display_menu();
		user_choice = get_menu_choice();


		switch (user_choice) {
		case OPTION_ADD_MANAGER:
		{
			Manager new_manager;
			input_manager(&new_manager);
			add_manager(&managers, &num_managers, new_manager); // Add the new manager
		}
		break;
		case OPTION_FIND_MANAGER:
		{
			int manager_id = input_find_manager_id();
			Manager* found_manager = find_manager(managers, num_managers, manager_id);
			print_manager(found_manager);
		}
		break;
		case OPTION_REMOVE_MANAGER:
		{
			int id = input_remove_manager_id();
			remove_manager(&managers, &num_managers, id);
			printf("Manager removed.\n");
			break;
		}
		case OPTION_UPDATE_MANAGER:
		{
			// Get the updated manager data
			Manager updated_manager;
			printf("Enter the updated manager data:\n");
			input_manager(&updated_manager);
			update_manager(managers, num_managers, updated_manager);
			printf("Manager updated.\n");
			break;
		}
		case OPTION_ADD_CLIENT:
		{
			Client new_client;
			input_client(&new_client);
			add_client(&clients, &num_clients, new_client); // Add the new client
		}
		break;
		case OPTION_FIND_CLIENT:
		{
			int nif = input_find_client_nif();
			Client* found_client = find_client(clients, num_clients, nif);
			print_client(found_client);
			break;
		}
		case OPTION_REMOVE_CLIENT:
		{
			int nif = input_remove_client_nif();
			remove_client(&clients, &num_clients, nif);
			printf("Client removed.\n");
			break;
		}
		case OPTION_UPDATE_CLIENT:
		{
			printf("Enter the updated client data:\n");
			Client updated_client;
			input_client(&updated_client);
			update_client(clients, num_clients, updated_client);
			printf("Client updated.\n");
			break;
		}
		case OPTION_ADD_MOBILITY_DEVICE:
		{
			MobilityDevice new_device;
			input_mobility_device(&new_device);
			add_mobility_device(&devices, &num_devices, new_device); // Add the new mobility device
		}
		break;
		case OPTION_FIND_MOBILITY_DEVICE:
		{
			int device_id = input_find_mobility_device_id();
			MobilityDevice* found_device = search_mobility_device(devices, num_devices, device_id);
			print_mobility_device(found_device);
			break;
		}
		case OPTION_REMOVE_MOBILITY_DEVICE:
		{
			int device_id = input_remove_mobility_device_id();
			remove_mobility_device(&devices, &num_devices, device_id);
			printf("Mobility device removed.\n");
			break;
		}
		case OPTION_UPDATE_MOBILITY_DEVICE:
		{
			printf("Enter the updated mobility device data:\n");
			MobilityDevice updated_device;
			input_mobility_device(&updated_device);
			update_mobility_device(devices, num_devices, updated_device);
			printf("Mobility device updated.\n");
			break;
		}
		case OPTION_LIST_MOBILITY_DEVICES:
		{
			list_mobility_devices(devices, num_devices);
			break;
		}
		case OPTION_LIST_DEVICES_BY_DESCENDING_AUTONOMY:
		{
			list_devices_by_descending_autonomy(devices, num_devices);
			break;
		}
		case OPTION_LIST_DEVICES_BY_GEOCODE:
		{
			char* geocode_to_find = input_geocode();
			list_devices_by_geocode(devices, num_devices, geocode_to_find);

			break;
		}
		case OPTION_REGISTER_RENTAL:
		{
			Rental new_rental;

			input_rental(&new_rental);
			if (validate_rental(clients, num_clients, devices, num_devices, rentals, num_rentals, &new_rental)) {
				add_rental(&rentals, &num_rentals, clients, num_clients, devices, num_devices, new_rental);
				printf("Rental registered successfully.\n");
			}
			else {
				printf("Invalid input, please try again.\n");
			}
		}
		break;
		case OPTION_MANAGER_DASHBOARD:
		{
			view_rental_history(rentals, num_rentals);
			calculate_statistics(rentals, num_rentals, clients, num_clients, devices, num_devices);
			validate_rental_data(rentals, num_rentals, clients, num_clients, devices, num_devices);
		}
		break;
		case OPTION_EXIT:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}

	} while (user_choice != OPTION_EXIT);


	// Save data to binary files
	save_data_to_binary_file(managers, sizeof(Manager), num_managers, "managers.bin");
	save_data_to_binary_file(clients, sizeof(Client), num_clients, "clients.bin");
	save_data_to_binary_file(devices, sizeof(MobilityDevice), num_devices, "devices.bin");
	save_data_to_binary_file(rentals, sizeof(Rental), num_rentals, "rentals.bin");


	// Free the memory allocated for the original and loaded data
	free(managers);
	free(clients);
	free(devices);
	free(rentals);

	return 0;
}

void initialize_and_load_data(Manager** managers, int* num_managers, Client** clients, int* num_clients, MobilityDevice** devices, int* num_devices, Rental** rentals, int* num_rentals) {
	// Load data from binary files
	*managers = load_data_from_binary_file(sizeof(Manager), num_managers, "managers.bin");
	*clients = load_data_from_binary_file(sizeof(Client), num_clients, "clients.bin");
	*devices = load_data_from_binary_file(sizeof(MobilityDevice), num_devices, "devices.bin");
	*rentals = load_data_from_binary_file(sizeof(Rental), num_rentals, "rentals.bin");

	// Initialize data files if they do not exist
	if (*managers == NULL) {
		initialize_data_file("managers.bin");
	}
	if (*clients == NULL) {
		initialize_data_file("clients.bin");
	}
	if (*devices == NULL) {
		initialize_data_file("devices.bin");
	}
	if (*rentals == NULL) {
		initialize_data_file("rentals.bin");
	}
}
