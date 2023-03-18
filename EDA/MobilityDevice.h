// MobilityDevice.h
#ifndef MOBILITYDEVICE_H
#define MOBILITYDEVICE_H

// Define structure for electric mobility devices
typedef struct {
    int id;
    char type[50];
    float battery_charge;
    float cost;
    char location[20];
} MobilityDevice;

// Functions
void add_mobility_device(MobilityDevice** devices, int* device_count, MobilityDevice new_device);
void remove_mobility_device(MobilityDevice** devices, int* device_count, int device_id);
MobilityDevice* search_mobility_device(MobilityDevice* devices, int device_count, int device_id);
void update_mobility_device(MobilityDevice* devices, int device_count, MobilityDevice updated_device);
void list_mobility_devices(MobilityDevice* devices, int device_count);
void mobility_device_to_string(MobilityDevice* mobility_device, char* str);
void print_mobility_device(MobilityDevice* device);


#endif // MOBILITYDEVICE_H