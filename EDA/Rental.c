#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "rental.h"
#include "client.h"
#include "mobilitydevice.h"
/**

@file rental.c
@brief Implementation file for the rental management system.
This file contains the implementation of functions for managing rentals in a mobility device rental system.
*/


/**

@brief Adds a rental to the system.
This function adds a rental to the system and updates the rented mobility device's is_rented field to 1.
Additionally, it subtracts the cost of the rented device from the client's balance.

@param rentals A pointer to an array of rentals.
@param num_rentals A pointer to the number of rentals in the array.
@param clients An array of clients.
@param num_clients The number of clients in the array.
@param devices An array of mobility devices.
@param num_devices The number of mobility devices in the array.
@param new_rental The rental to add to the system.
*/
void add_rental(Rental** rentals, int* num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices, Rental new_rental) {
    *num_rentals += 1;
    *rentals = (Rental*)realloc_safe(*rentals, *num_rentals * sizeof(Rental));
    (*rentals)[*num_rentals - 1] = new_rental;

    // Find the rented device and set its is_rented field to 1
    MobilityDevice* rented_device = search_mobility_device(devices, num_devices, new_rental.device_id);
    if (rented_device != NULL) {
        rented_device->is_rented = 1;
    }

    // Find the client and subtract the cost from their balance
    Client* client = find_client(clients, num_clients, new_rental.client_nif);
    if (client != NULL) {
        client->balance -= rented_device->cost;
    }
}

/**
@brief Finds a rental by ID.
This function finds a rental by its ID and returns a pointer to it.
@param rentals An array of rentals.
@param num_rentals The number of rentals in the array.
@param rental_id The ID of the rental to find.
@return A pointer to the rental if found, or NULL if not found.
*/
Rental* find_rental(Rental* rentals, int num_rentals, int rental_id) {
    for (int i = 0; i < num_rentals; i++) {
        if (rentals[i].id == rental_id) {
            return &rentals[i];
        }
    }
    return NULL;
}

/**

@brief Validates a rental.
This function validates a rental by checking if the client and mobility device exist, if the device is
already rented, and if the client has enough balance to rent the device. Returns 1 if the rental is valid,
and 0 otherwise.
@param clients An array of clients.
@param num_clients The number of clients in the array.
@param devices An array of mobility devices.
@param num_devices The number of mobility devices in the array.
@param rentals An array of rentals.
@param num_rentals The number of rentals in the array.
@param rental The rental to validate.
@return 1 if the rental is valid, 0 otherwise.
*/
int validate_rental(Client* clients, int num_clients, MobilityDevice* devices, int num_devices, Rental* rentals, int num_rentals, Rental* rental) {
    // Check if the client exists
    Client* client = find_client(clients, num_clients, rental->client_nif);
    if (client == NULL) {
        printf("Client not found.\n");
        return 0;
    }

    // Check if the mobility device exists
    MobilityDevice* device = search_mobility_device(devices, num_devices, rental->device_id);
    if (device == NULL) {
        printf("Mobility device not found.\n");
        return 0;
    }

    // Check if the device is already rented
    if (device->is_rented) {
        printf("Mobility device is already rented.\n");
        return 0;
    }

    // Check if the device is already rented
    for (int i = 0; i < num_rentals; i++) {
        if (rentals[i].device_id == rental->device_id) {
            printf("Mobility device is already rented.\n");
            return 0;
        }
    }

    return 1;
}



