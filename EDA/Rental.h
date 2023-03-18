// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "client.h"
#include "mobilitydevice.h"

/**
 * @file Rental.h
 * @brief Contains the Rental structure and related functions.
 */

 /**
  * @brief Define structure for rentals.
  */
typedef struct Rental {
    int id;
    int client_nif;
    int device_id;
    int rental_duration; // in minutes
} Rental;

// Functions

/**
 * @brief Adds a new rental to the array.
 */
void add_rental(Rental** rentals, int* num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices, Rental new_rental);

/**
 * @brief Finds a rental in the array using its ID.
 */
Rental* find_rental(Rental* rentals, int num_rentals, int rental_id);

/**
 * @brief Validates a rental.
 */
int validate_rental(Client* clients, int num_clients, MobilityDevice* devices, int num_devices, Rental* rentals, int num_rentals, Rental* rental);


#endif // RENTAL_H
