#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "client.h"

// Adds a new client to the array of clients
void add_client(Client** clients, int* num_clients, Client new_client) {
    // Resize the clients array to accommodate the new client
    *clients = (Client*)realloc_safe(*clients, (*num_clients + 1) * sizeof(Client));

    if (*clients == NULL) {
        // Handle the memory allocation failure, e.g., continue with reduced functionality
        return;
    }

    // Add the new client to the array
    (*clients)[*num_clients] = new_client;

    // Increment the number of clients
    (*num_clients)++;
}

// Removes a client from the array of clients using their NIF
void remove_client(Client** clients, int* num_clients, int nif) {
    // Iterate through the clients array
    for (int i = 0; i < *num_clients; i++) {
        // If the client's NIF matches the provided NIF
        if ((*clients)[i].nif == nif) {
            // Shift all clients to the right of the matched client to the left
            for (int j = i; j < *num_clients - 1; j++) {
                (*clients)[j] = (*clients)[j + 1];
            }

            // Resize the clients array to remove the matched client
            *clients = (Client*)realloc_safe(*clients, (*num_clients - 1) * sizeof(Client));

            if (*clients == NULL) {
                // Handle the memory allocation failure, e.g., continue with reduced functionality
                return;
            }

            // Decrement the number of clients
            (*num_clients)--;

            // Exit the loop
            break;
        }
    }
}

// Updates an existing client in the array of clients
void update_client(Client* clients, int num_clients, Client updated_client) {
    // Iterate through the clients array
    for (int i = 0; i < num_clients; i++) {
        // If the client's NIF matches the updated client's NIF
        if (clients[i].nif == updated_client.nif) {
            // Update the client with the new data
            clients[i] = updated_client;

            // Exit the loop
            break;
        }
    }
}

// Finds a client in the array of clients using their NIF and returns a pointer to the client
Client* find_client(Client* clients, int num_clients, int nif) {
    // Iterate through the clients array
    for (int i = 0; i < num_clients; i++) {
        // If the client's NIF matches the provided NIF
        if (clients[i].nif == nif) {
            // Return a pointer to the matched client
            return &clients[i];
        }
    }
    // If no client is found, return NULL
    return NULL;
}
