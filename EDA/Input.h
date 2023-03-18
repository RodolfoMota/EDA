// Input.h
#ifndef INPUT_H
#define INPUT_H

/**
 * @file Input.h
 * @brief Contains input functions for the various structures.
 */

#include "manager.h"
#include "client.h"
#include "mobilitydevice.h"
#include "rental.h"

 /**
  * @brief Reads input for a Manager structure from the user.
  *
  * @param manager Pointer to the Manager structure to fill with user input.
  */
void input_manager(Manager* manager);

/**
 * @brief Reads input for a manager ID to find.
 *
 * @return The manager ID to find.
 */
int input_find_manager_id(void);

/**
 * @brief Reads input for a manager ID to remove.
 *
 * @return The manager ID to remove.
 */
int input_remove_manager_id(void);

/**
 * @brief Prints the information of a Manager structure.
 *
 * @param manager Pointer to the Manager structure to print.
 */
void print_manager(Manager* manager);

/**
 * @brief Reads input for a Client structure from the user.
 *
 * @param client Pointer to the Client structure to fill with user input.
 */
void input_client(Client* client);

/**
 * @brief Reads input for a client NIF to find.
 *
 * @return The client NIF to find.
 */
int input_find_client_nif(void);

/**
 * @brief Reads input for a client NIF to remove.
 *
 * @return The client NIF to remove.
 */
int input_remove_client_nif(void);

/**
 * @brief Reads input for a MobilityDevice structure from the user.
 *
 * @param mobility_device Pointer to the MobilityDevice structure to fill with user input.
 */
void input_mobility_device(MobilityDevice* mobility_device);

/**
 * @brief Reads input for a mobility device ID to find.
 *
 * @return The mobility device ID to find.
 */
int input_find_mobility_device_id(void);

/**
 * @brief Reads input for a mobility device ID to remove.
 *
 * @return The mobility device ID to remove.
 */
int input_remove_mobility_device_id(void);

/**
 * @brief Reads input for a geocode string.
 *
 * @return Pointer to the geocode string.
 */
char* input_geocode(void);

/**
 * @brief Reads input for a Rental structure from the user.
 *
 * @param rental Pointer to the Rental structure to fill with user input.
 */
void input_rental(Rental* rental);

/**
 * @brief Prints the information of a Rental structure.
 *
 * @param rental Pointer to the Rental structure to print.
 */
void print_rental(Rental* rental);

#endif // INPUT_H
