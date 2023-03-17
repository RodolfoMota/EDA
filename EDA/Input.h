#ifndef INPUT_H
#define INPUT_H

#include "manager.h"
#include "client.h"
#include "mobilitydevice.h"

void input_manager(Manager* manager);
void input_client(Client* client);
void input_mobility_device(MobilityDevice* mobility_device);

#endif // INPUT_H
