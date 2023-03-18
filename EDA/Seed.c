#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "seed.h"
#include "utils.h"
#include "Client.h"
#include "MobilityDevice.h"
#include "Manager.h"


void generate_seed_data() {
	// Declare pointers for the arrays and their counts
	Manager* managers = NULL;
	int num_managers = 0;

	Client* clients = NULL;
	int num_clients = 0;

	MobilityDevice* devices = NULL;
	int num_devices = 0;

	// Manipulate the data (add, update, remove)
	// Add a manager
	Manager new_manager = { 1, "Rodolfo", "rodolfo@example.com" };
	add_manager(&managers, &num_managers, new_manager);

	Manager new_manager1 = { 2, "Rodolfo2", "rodolfo2@example.com" };
	add_manager(&managers, &num_managers, new_manager1);

	// Add a client
	Client new_client = { 123123123, 15, "Jane Smith", "jane@example.com" };
	add_client(&clients, &num_clients, new_client);

	Client new_client2 = { 123123124, 25, "Alice", "alice@example.com" };
	add_client(&clients, &num_clients, new_client2);

	// Add a mobility device
	MobilityDevice new_device1 = { 1, "Scooter", 85.0, 0.25, "New York" };
	add_mobility_device(&devices, &num_devices, new_device1);

	MobilityDevice new_device2 = { 2, "Bike", 100.0, 0.75, "San Francisco" };
	add_mobility_device(&devices, &num_devices, new_device2);

	MobilityDevice new_device3 = { 3, "E-Bike", 60.0, 0.5, "Los Angeles" };
	add_mobility_device(&devices, &num_devices, new_device3);

	MobilityDevice new_device4 = { 4, "Skateboard", 70.0, 0.15, "Miami" };
	add_mobility_device(&devices, &num_devices, new_device4);

	// Saving managers to a text file
	save_data_to_text_file(managers, sizeof(Manager), num_managers, "managers.txt", (void (*)(FILE*, void*))manager_to_string);
	save_data_to_text_file(clients, sizeof(Client), num_clients, "client.txt", (void (*)(FILE*, void*))client_to_string);
	save_data_to_text_file(devices, sizeof(MobilityDevice), num_devices, "mobilitydevice.txt", (void (*)(FILE*, void*))mobility_device_to_string);

	free(managers);
	free(clients);
	free(devices);
}
