// Client.h
#ifndef CLIENT_H
#define CLIENT_H

/**
 * @file Client.h
 * @brief Contains the Client structure and its related functions.
 */

 /**
  * @struct Client
  * @brief Defines the Client structure.
  */
typedef struct {
    int nif;                 /**< Client's NIF (Tax Identification Number) */
    float balance;           /**< Client's account balance */
    char name[100];          /**< Client's name */
    char email[200];         /**< Client's email address */
} Client;

/**
 * @brief Adds a new client to the list of clients.
 *
 * @param clients Pointer to the list of clients.
 * @param num_clients Pointer to the number of clients in the list.
 * @param new_client The new client to add.
 */
void add_client(Client** clients, int* num_clients, Client new_client);

/**
 * @brief Removes a client from the list of clients.
 *
 * @param clients Pointer to the list of clients.
 * @param num_clients Pointer to the number of clients in the list.
 * @param nif The NIF of the client to remove.
 */
void remove_client(Client** clients, int* num_clients, int nif);

/**
 * @brief Updates a client's information in the list of clients.
 *
 * @param clients The list of clients.
 * @param num_clients The number of clients in the list.
 * @param updated_client The updated client information.
 */
void update_client(Client* clients, int num_clients, Client updated_client);

/**
 * @brief Finds a client in the list of clients by their NIF.
 *
 * @param clients The list of clients.
 * @param num_clients The number of clients in the list.
 * @param nif The NIF of the client to find.
 * @return Pointer to the found client, or NULL if not found.
 */
Client* find_client(Client* clients, int num_clients, int nif);

/**
 * @brief Converts a client to a string.
 *
 * @param client Pointer to the client to convert.
 * @param str Pointer to the string to store the converted client.
 */
void client_to_string(Client* client, char* str);

/**
 * @brief Prints a client's information.
 *
 * @param client Pointer to the client to print.
 */
void print_client(Client* client);

#endif // CLIENT_H
