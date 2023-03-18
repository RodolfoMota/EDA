#ifndef INPUT_H
#define INPUT_H

#include "manager.h"
#include "client.h"
#include "mobilitydevice.h"
#include "rental.h"

void input_manager(Manager* manager);
int input_find_manager_id(void);
int input_remove_manager_id(void);
void print_manager(Manager* manager);

void input_client(Client* client);
int input_find_client_nif(void);
int input_remove_client_nif(void);

void input_mobility_device(MobilityDevice* mobility_device);
int input_find_mobility_device_id(void);
int input_remove_mobility_device_id(void);
char* input_geocode(void);


void input_rental(Rental* rental);
void print_rental(Rental* rental);


#endif // INPUT_H
