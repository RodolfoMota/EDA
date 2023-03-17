#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "manager.h"
#include "client.h"
#include "mobilitydevice.h"


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
    int option;

    // Manipulate the data (add, update, remove)
    // Add a manager
    Manager new_manager = { 1, "John Doe", "john@example.com" };
    add_manager(&managers, &num_managers, new_manager);

    // Add a client
    Client new_client = { 1, 15, "Jane Smith", "jane@example.com" };
    add_client(&clients, &num_clients, new_client);

    // Add a mobility device
    MobilityDevice new_device = { 1, "Scooter", 85.0, 0.25, "New York" };
    add_mobility_device(&devices, &num_devices, new_device);

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

#pragma region To Do

    //do {
    //    printf("\nMicromobility Management System\n");
    //    printf("1. Insert Data (Client/Manager/Mobility Device)\n");
    //    printf("2. Remove Data (Client/Manager/Mobility Device)\n");
    //    printf("3. Update Data (Client/Manager/Mobility Device)\n");
    //    printf("4. Register Rental\n");
    //    printf("5. List Devices by Autonomy\n");
    //    printf("6. List Devices by Location\n");
    //    printf("0. Exit\n");
    //    printf("Choose an option: ");
    //    scanf_s("%d", &option);

    //    switch (option) {
    //    case 1:
    //       
    //        break;
    //    case 2:
    //   
    //        break;
    //    case 3:
    //      
    //        break;
    //    case 4:
    //       
    //        break;
    //    case 5:
    //        
    //        break;
    //    case 6:
    //       
    //        break;
    //    case 0:
    //        printf("Exiting...\n");
    //        break;
    //    default:
    //        printf("Invalid option. Please try again.\n");
    //    }
    //} while (option != 0);

#pragma endregion


    return 0;
}

