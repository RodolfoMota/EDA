#ifndef RENTAL_H
#define RENTAL_H

#include "client.h"
#include "mobilitydevice.h"

typedef struct Rental {
    int id;
    int client_nif;
    int device_id;
    int rental_duration; // in minutes
} Rental;


void add_rental(Rental** rentals, int* num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices, Rental new_rental);
Rental* find_rental(Rental* rentals, int num_rentals, int rental_id);
int validate_rental(Client* clients, int num_clients, MobilityDevice* devices, int num_devices, Rental* rentals, int num_rentals, Rental* rental);


#endif // RENTAL_H
