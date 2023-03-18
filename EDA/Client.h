// Client.h
#ifndef CLIENT_H
#define CLIENT_H


// Define the Client structure
typedef struct {
    int nif;
    float balance;
    char name[100];
    char email[200];
} Client;

// Function
void add_client(Client** clients, int* num_clients, Client new_client);
void remove_client(Client** clients, int* num_clients, int nif);
void update_client(Client* clients, int num_clients, Client updated_client);
Client* find_client(Client* clients, int num_clients, int nif);
void client_to_string(Client* client, char* str);
void print_client(Client* client);

#endif // CLIENT_H