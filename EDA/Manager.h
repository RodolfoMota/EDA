// Manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include "Rental.h"

// Define the Manager structure
typedef struct {
    int id;
    char name[100];
    char position[100];
} Manager;

// Functions
void add_manager(Manager** managers, int* num_managers, Manager new_manager);
void remove_manager(Manager** managers, int* num_managers, int id);
void update_manager(Manager* managers, int num_managers, Manager updated_manager);
Manager* find_manager(Manager* managers, int num_managers, int id);

//Dashboard
void view_rental_history(Rental* rentals, int num_rentals);
void calculate_statistics(Rental* rentals, int num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices);
void validate_rental_data(Rental* rentals, int num_rentals, Client* clients, int num_clients, MobilityDevice* devices, int num_devices);


#endif // MANAGER_H