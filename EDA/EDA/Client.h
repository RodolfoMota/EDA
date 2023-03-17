// Client.h
#ifndef CLIENT_H
#define CLIENT_H


// Define the Client structure
typedef struct {
    int nif;
    float balance;
    char name[100];
    char address[200];
} Client;

// Function
void add_client(Client** clients, int* num_clients, Client new_client);
void remove_client(Client** clients, int* num_clients, int nif);
void update_client(Client* clients, int num_clients, Client updated_client);
Client* find_client(Client* clients, int num_clients, int nif);

#endif // CLIENT_H