// MobilityDevice.h
#ifndef MOBILITYDEVICE_H
#define MOBILITYDEVICE_H

/**
 * @file MobilityDevice.h
 * @brief Contains the MobilityDevice structure and related functions.
 */

 /**
  * @brief Define structure for electric mobility devices.
  */
typedef struct {
    int id;
    char type[50];
    float autonomy;
    float cost;
    char geocode[30];
    int is_rented;
} MobilityDevice;

// Functions

/**
 * @brief Adds a new mobility device to the array.
 */
void add_mobility_device(MobilityDevice** devices, int* device_count, MobilityDevice new_device);

/**
 * @brief Removes a mobility device from the array using its ID.
 */
void remove_mobility_device(MobilityDevice** devices, int* device_count, int device_id);

/**
 * @brief Searches for a mobility device using its ID.
 */
MobilityDevice* search_mobility_device(MobilityDevice* devices, int device_count, int device_id);

/**
 * @brief Updates the information of a mobility device.
 */
void update_mobility_device(MobilityDevice* devices, int device_count, MobilityDevice updated_device);

/**
 * @brief Lists all the mobility devices.
 */
void list_mobility_devices(MobilityDevice* devices, int device_count);

/**
 * @brief Prints the information of a single mobility device.
 */
void print_mobility_device(MobilityDevice* device);

/**
 * @brief Lists the mobility devices sorted by descending autonomy.
 */
void list_devices_by_descending_autonomy(MobilityDevice* devices, int num_devices);

/**
 * @brief Lists the mobility devices located at a specific geocode.
 */
void list_devices_by_geocode(MobilityDevice* devices, int num_devices, const char* geocode);


#endif // MOBILITYDEVICE_H
