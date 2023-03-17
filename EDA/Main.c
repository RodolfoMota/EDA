#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "menu.h"
#include "input.h"

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


// Main function with menu
int main() {

	// Declare pointers for the arrays and their counts
	Manager* managers = NULL;
	int num_managers = 0;

	Client* clients = NULL;
	int num_clients = 0;

	MobilityDevice* devices = NULL;
	int num_devices = 0;


#pragma region Load/Save txt
	// Saving managers to a text file
	save_data_to_text_file(managers, sizeof(Manager), num_managers, "managers.txt", (void (*)(FILE*, void*))manager_to_string);


	// Loading managers from a text file
	Manager* loaded_managers2 = load_data_from_text_file(sizeof(Manager), &num_managers, "managers.txt", (void (*)(FILE*, void*))string_to_manager);

#pragma endregion



#pragma region Load/Save binary
	// Save data to binary files
	save_data_to_binary_file(managers, sizeof(Manager), num_managers, "managers.bin");
	save_data_to_binary_file(clients, sizeof(Client), num_clients, "clients.bin");
	save_data_to_binary_file(devices, sizeof(MobilityDevice), num_devices, "devices.bin");

	// Load data from binary files
	int loaded_num_managers, loaded_num_clients, loaded_num_devices;
	Manager* loaded_managers = load_data_from_binary_file(sizeof(Manager), &loaded_num_managers, "managers.bin");
	Client* loaded_clients = load_data_from_binary_file(sizeof(Client), &loaded_num_clients, "clients.bin");
	MobilityDevice* loaded_devices = load_data_from_binary_file(sizeof(MobilityDevice), &loaded_num_devices, "devices.bin");

	// Free the memory allocated for the original and loaded data
	free(managers);
	free(clients);
	free(devices);
	free(loaded_managers);
	free(loaded_clients);
	free(loaded_devices);
#pragma endregion


	MenuOption user_choice;
	do {
		display_menu();
		user_choice = get_menu_choice();

		switch (user_choice) {
		case OPTION_ADD_MANAGER:
			// Use the input_manager function
			Manager new_manager;
			input_manager(&new_manager);
			break;
		case OPTION_ADD_CLIENT:
			// Use the input_client function
			Client new_client;
			input_client(&new_client);
			break;
		case OPTION_ADD_MOBILITY_DEVICE:
			// Use the input_mobility_device function
			MobilityDevice new_device;
			input_mobility_device(&new_device);
			break;
		case OPTION_EXIT:
			printf("Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	} while (user_choice != OPTION_EXIT);

	return 0;
}