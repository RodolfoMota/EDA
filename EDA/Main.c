#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "menu.h"
#include "input.h"
#include "seed.h"

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

void initialize_and_load_data(Manager** managers, int* num_managers, Client** clients, int* num_clients, MobilityDevice** devices, int* num_devices);


// Main function with menu
int main() {

	// Declare pointers for the arrays and their counts
	Manager* managers = NULL;
	Client* clients = NULL;
	MobilityDevice* devices = NULL;

	int num_managers, num_clients, num_devices = 0;


	// Initialize and load data
	initialize_and_load_data(&managers, &num_managers, &clients, &num_clients, &devices, &num_devices);


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
			int manager_id;
			printf("Enter the manager ID to search for: ");
			scanf_s("%d", &manager_id);
			Manager* found_manager = find_manager(managers, num_managers, manager_id);
			if (found_manager != NULL) {
				printf("Manager found: ID=%d, Name=%s, Position=%df\n",
					found_manager->id, found_manager->name, found_manager->position);
			}
			else {
				printf("Manager not found.\n");
			}
		}
		break;
		case OPTION_REMOVE_MANAGER:
		{
			// Get the ID of the manager to remove
			printf("Enter the ID of the manager to remove: ");
			int id;
			scanf_s("%d", &id);
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
			printf("Enter the NIF of the client to find: ");
			int nif;
			scanf_s("%d", &nif);
			Client* found_client = find_client(clients, num_clients, nif);
			if (found_client != NULL) {
				printf("Client found:\n");
				print_client(found_client);
			}
			else {
				printf("Client not found.\n");
			}
			break;
		}
		case OPTION_REMOVE_CLIENT:
		{
			printf("Enter the NIF of the client to remove: ");
			int nif;
			scanf_s("%d", &nif);
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
			printf("Enter the ID of the mobility device to find: ");
			int device_id;
			scanf_s("%d", &device_id);
			MobilityDevice* found_device = search_mobility_device(devices, num_devices, device_id);
			if (found_device != NULL) {
				printf("Mobility device found:\n");
				print_mobility_device(found_device);
			}
			else {
				printf("Mobility device not found.\n");
			}
			break;
		}
		case OPTION_REMOVE_MOBILITY_DEVICE:
		{
			printf("Enter the ID of the mobility device to remove: ");
			int device_id;
			scanf_s("%d", &device_id);
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


	// Free the memory allocated for the original and loaded data
	free(managers);
	free(clients);
	free(devices);

	return 0;
}

void initialize_and_load_data(Manager** managers, int* num_managers, Client** clients, int* num_clients, MobilityDevice** devices, int* num_devices) {
	// Load data from binary files
	*managers = load_data_from_binary_file(sizeof(Manager), num_managers, "managers.bin");
	*clients = load_data_from_binary_file(sizeof(Client), num_clients, "clients.bin");
	*devices = load_data_from_binary_file(sizeof(MobilityDevice), num_devices, "devices.bin");

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
}
