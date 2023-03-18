#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "rental.h"
#include "client.h"
#include "mobilitydevice.h"

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


Rental* find_rental(Rental* rentals, int num_rentals, int rental_id) {
    for (int i = 0; i < num_rentals; i++) {
        if (rentals[i].id == rental_id) {
            return &rentals[i];
        }
    }
    return NULL;
}

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



