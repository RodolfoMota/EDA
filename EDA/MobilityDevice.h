// MobilityDevice.h
#ifndef MOBILITYDEVICE_H
#define MOBILITYDEVICE_H

// Define structure for electric mobility devices
typedef struct {
    int id;
    char type[50];
    float autonomy;
    float cost;
    char geocode[20];
    int is_rented;
} MobilityDevice;

// Functions
void add_mobility_device(MobilityDevice** devices, int* device_count, MobilityDevice new_device);
void remove_mobility_device(MobilityDevice** devices, int* device_count, int device_id);
MobilityDevice* search_mobility_device(MobilityDevice* devices, int device_count, int device_id);
void update_mobility_device(MobilityDevice* devices, int device_count, MobilityDevice updated_device);
void list_mobility_devices(MobilityDevice* devices, int device_count);
void print_mobility_device(MobilityDevice* device);
void list_devices_by_descending_autonomy(MobilityDevice* devices, int num_devices);
void list_devices_by_geocode(MobilityDevice* devices, int num_devices, const char* geocode);


#endif // MOBILITYDEVICE_H