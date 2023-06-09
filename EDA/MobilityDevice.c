#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "mobilitydevice.h"
#include <stdbool.h> // For the 'bool' type
/**
 * @file mobilitydevice.c
 * @brief Functions for managing the fleet of mobility devices.
 */



/**
 * @brief Adds a new mobility device to the array of devices.
 *
 * @param devices Pointer to the array of devices.
 * @param device_count Pointer to the number of devices in the array.
 * @param new_device The new device to add.
 */
void add_mobility_device(MobilityDevice** devices, int* device_count, MobilityDevice new_device) {
	// Increment the number of devices
	(*device_count)++;

	// Resize the devices array to accommodate the new device
	*devices = realloc_safe(*devices, *device_count * sizeof(MobilityDevice));

	if (*devices == NULL) {
		// Handle the memory allocation failure, e.g., continue with reduced functionality
		return;
	}

	// Add the new device to the array
	(*devices)[*device_count - 1] = new_device;
}

/**
 * @brief Removes a mobility device from the array of devices using its ID.
 *
 * @param devices Pointer to the array of devices.
 * @param device_count Pointer to the number of devices in the array.
 * @param device_id The ID of the device to remove.
 */
void remove_mobility_device(MobilityDevice** devices, int* device_count, int device_id) {
	int found = 0;

	// Iterate through the devices array
	for (int i = 0; i < *device_count; i++) {
		// If the device's ID matches the provided ID, mark as found
		if ((*devices)[i].id == device_id) {
			found = 1;
		}

		// If the device is found and not the last in the array, shift the devices to the left
		if (found && i < *device_count - 1) {
			(*devices)[i] = (*devices)[i + 1];
		}
	}

	// If the device was found, resize the devices array and decrement the device count
	if (found) {
		(*device_count)--;
		*devices = realloc_safe(*devices, *device_count * sizeof(MobilityDevice));
		if (*devices == NULL) {
			// Handle the memory allocation failure, e.g., continue with reduced functionality
			return;
		}
	}
}

/**
 * @brief Searches for a mobility device in the array using its ID and returns a pointer to the device.
 *
 * @param devices Pointer to the array of devices.
 * @param device_count The number of devices in the array.
 * @param device_id The ID of the device to find.
 * @return Pointer to the matched mobility device, or NULL if no device is found.
 */
MobilityDevice* search_mobility_device(MobilityDevice* devices, int device_count, int device_id) {
	// Iterate through the devices array
	for (int i = 0; i < device_count; i++) {
		// If the device's ID matches the provided ID, return a pointer to the matched device
		if (devices[i].id == device_id) {
			return &devices[i];
		}
	}
	// If no device is found, return NULL
	return NULL;
}

/**
 * @brief Updates a mobility device's information in the array using an updated device object.
 *
 * @param devices Pointer to the array of devices.
 * @param device_count The number of devices in the array.
 * @param updated_device The updated device object.
 */
void update_mobility_device(MobilityDevice* devices, int device_count, MobilityDevice updated_device) {
	// Find the device to update using its ID
	MobilityDevice* device_to_update = search_mobility_device(devices, device_count, updated_device.id);

	// If the device is found, update its information with the new data
	if (device_to_update) {
		*device_to_update = updated_device;
	}
}

/**
 * @brief Lists all the mobility devices in the array with their details.
 *
 * @param devices Pointer to the array of devices.
 * @param device_count The number of devices in the array.
 */
void list_mobility_devices(MobilityDevice* devices, int device_count) {
	printf("\nList of Mobility Devices:\n");

	// Iterate through the devices array and print each device's information
	for (int i = 0; i < device_count; i++) {
		printf("ID: %d, Type: %s, Battery: %.2f%%, Cost: %.2f, Location: %s\n",
			devices[i].id, devices[i].type, devices[i].autonomy, devices[i].cost, devices[i].geocode);
	}
}

/**
 * @brief Lists all the mobility devices in the array by descending autonomy.
 *
 * @param devices Pointer to the array of devices.
 * @param num_devices The number of devices in the array.
 */
void list_devices_by_descending_autonomy(MobilityDevice* devices, int num_devices) {
	// Sort the devices by descending autonomy using Bubble Sort
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < num_devices - 1; i++) {
			if (devices[i].autonomy < devices[i + 1].autonomy) {
				MobilityDevice temp = devices[i];
				devices[i] = devices[i + 1];
				devices[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped);

	// Print the sorted devices
	printf("Mobility devices sorted by descending autonomy:\n");
	for (int i = 0; i < num_devices; i++) {
		print_mobility_device(&devices[i]);
	}
}

/**
 * @brief Prints the details of a mobility device.
 *
 * @param device Pointer to the mobility device to print.
 */
void print_mobility_device(MobilityDevice* device) {
	if (device == NULL) {
		printf("Device not found.\n");
	}
	else {
		printf("Mobility device found:\n");
		printf("ID: %d, Type: %s, Battery: %.2f%%, Cost: %.2f, Location: %s\n",
			device->id, device->type, device->autonomy, device->cost, device->geocode);
	}
}

/**
 * @brief Lists all the mobility devices in the array with a specific geocode.
 *
 * @param devices Pointer to the array of devices.
 * @param num_devices The number of devices in the array.
 * @param geocode The geocode to search for.
 */
void list_devices_by_geocode(MobilityDevice* devices, int num_devices, const char* geocode) {
	printf("Mobility devices with geocode: %s\n", geocode);
	printf("ID\tName\tAutonomy\tRented\n");
	for (int i = 0; i < num_devices; i++) {
		if (strcmp(devices[i].geocode, geocode) == 0) {
			printf("%d\t%s\t%.2f\t%d\n", devices[i].id, devices[i].type, devices[i].autonomy, devices[i].is_rented);
		}
	}
}
