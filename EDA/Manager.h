// Manager.h
#ifndef MANAGER_H
#define MANAGER_H

/**
 * @file Manager.h
 * @brief Contains the Manager structure and related functions.
 */

#include "Rental.h"

 /**
  * @brief The Manager structure.
  */
typedef struct {
    int id;
    char name[100];
    char position[100];
} Manager;

/**
 * @brief Adds a new manager to the managers array.
 *
 * @param managers Pointer to the array of managers.
 * @param num_managers Pointer to the number of managers in the array.
 * @param new_manager The new manager to add.
 */
void add_manager(Manager** managers, int* num_managers, Manager new_manager);

/**
 * @brief Removes a manager from the managers array.
 *
 * @param managers Pointer to the array of managers.
 * @param num_managers Pointer to the number of managers in the array.
 * @param id The ID of the manager to remove.
 */
void remove_manager(Manager** managers, int* num_managers, int id);

/**
 * @brief Updates a manager in the managers array.
 *
 * @param managers Pointer to the array of managers.
 * @param num_managers The number of managers in the array.
 * @param updated_manager The updated manager data.
 */
void update_manager(Manager* managers, int num_managers, Manager updated_manager);

/**
 * @brief Finds a manager by ID.
 *
 * @param managers Pointer to the array of managers.
 * @param num_managers The number of managers in the array.
 * @param id The ID of the manager to find.
 * @return Pointer to the found manager, or NULL if not found.
 */
Manager* find_manager(Manager* managers, int num_managers, int id);

// Dashboard
/**
 * @brief Views the rental history of all rentals.
 *
 * @param rentals Pointer to the array of rentals.
 * @param num_rentals The number of rentals in the array.
 */
void view_rental_history(Rental* rentals, int num_rentals);

/**
 * @brief Calculates statistics about the rentals, clients, and devices.
 *
 * @param rentals Pointer to the array of rentals.
 * @param num_rentals The number of rentals in the array.
 * @param clients Pointer to the array of clients.
 * @param num_clients The number of clients in the array.
 * @param devices Pointer to the array of mobility devices.
 * @param num_devices The number of mobility devices in the array.
 */
void calculate_statistics(Rental* rentals, int num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices);

/**
 * @brief Validates rental data by checking if clients and devices exist and if devices are rented.
 *
 * @param rentals Pointer to the array of rentals.
 * @param num_rentals The number of rentals in the array.
 * @param clients Pointer to the array of clients.
 * @param num_clients The number of clients in the array.
 * @param devices Pointer to the array of mobility devices.
 * @param num_devices The number of mobility devices in the array.
 */
void validate_rental_data(Rental* rentals, int num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices);

#endif // MANAGER
