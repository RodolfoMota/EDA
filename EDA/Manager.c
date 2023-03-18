#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "manager.h"

// Adds a new manager to the array of managers
void add_manager(Manager** managers, int* num_managers, Manager new_manager) {

	// Resize the managers array to accommodate the new manager
	*managers = (Manager*)realloc_safe(*managers, (*num_managers + 1) * sizeof(Manager));

	if (*managers == NULL) {
		// Handle the memory allocation failure, e.g., continue with reduced functionality
		return;
	}

	// Add the new manager to the array
	(*managers)[*num_managers] = new_manager;

	// Increment the number of managers
	(*num_managers)++;
}

// Removes a manager from the array of managers using their ID
void remove_manager(Manager** managers, int* num_managers, int id) {
	// Iterate through the managers array
	for (int i = 0; i < *num_managers; i++) {
		// If the manager's ID matches the provided ID
		if ((*managers)[i].id == id) {
			// Shift all managers to the right of the matched manager to the left
			for (int j = i; j < *num_managers - 1; j++) {
				(*managers)[j] = (*managers)[j + 1];
			}

			// Resize the managers array to remove the matched manager
			*managers = (Manager*)realloc_safe(*managers, (*num_managers - 1) * sizeof(Manager));

			if (*managers == NULL) {
				// Handle the memory allocation failure, e.g., continue with reduced functionality
				return;
			}

			// Decrement the number of managers
			(*num_managers)--;

			// Exit the loop
			break;
		}
	}
}

// Updates an existing manager in the array of managers
void update_manager(Manager* managers, int num_managers, Manager updated_manager
) {
	// Iterate through the managers array
	for (int i = 0; i < num_managers; i++) {
		// If the manager's ID matches the updated manager's ID
		if (managers[i].id == updated_manager.id) {
			// Update the manager with the new data
			managers[i] = updated_manager;

			// Exit the loop
			break;
		}
	}
}

// Finds a manager in the array of managers using their ID and returns a pointer to the manager
Manager* find_manager(Manager* managers, int num_managers, int id) {
	// Iterate through the managers array
	for (int i = 0; i < num_managers; i++) {
		// If the manager's ID matches the provided ID
		if (managers[i].id == id) {
			// Return a pointer to the matched manager
			return &managers[i];
		}
	}
	// If no manager is found, return NULL
	return NULL;
}


