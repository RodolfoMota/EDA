
# Mobility Device Rental System

This project is a Mobility Device Rental System that allows users to manage clients, managers, mobility devices, and rentals. The system is designed for a company that offers electric mobility devices (such as e-scooters or e-bikes) for rent to its clients. The main goal of the system is to facilitate the management of available devices, client information, and rental transactions.

The Mobility Device Rental System provides an interactive menu to the user, offering options to perform various tasks such as adding, removing, updating, and searching for managers, clients, and mobility devices. It also allows users to register rentals, view rental history, and calculate rental statistics.

The system utilizes several data structures, including structs to represent managers, clients, mobility devices, and rentals. Additionally, it uses a dynamic data structure to represent the location of clients and mobility devices, employing a graph for this purpose.

Each mobility device is equipped with location information, including latitude and longitude coordinates, allowing for easy tracking and management of the devices. This information can be used to display the devices available in a specific area or to analyze the usage patterns of the devices.


## Features

- Add, remove, update, and search for managers, clients, and mobility devices
- Register rentals
- View rental history
- Calculate rental statistics
- Track and manage device locations using latitude and longitude coordinates


## Getting Started

To compile the project, navigate to the project directory and run the following command:

```bash
gcc main.c manager.c client.c mobilitydevice.c utils.c input.c location.c menu.c -o rental_system
```

To run the compiled program, execute the following command:


```bash
./rental_system
```
    
The system will then display the main menu, allowing you to select from the available options.
## File Structure

```bash
project/
│
├── main.c
├── client.c
├── manager.c
├── mobilitydevice.c
├── utils.c
├── input.c
├── location.c
├── menu.c
│
├── client.h
├── manager.h
├── mobilitydevice.h
├── utils.h
├── input.h
├── location.h
└── menu.h

```
## Dependencies

The project uses only the standard C library, so no additional dependencies are required.
## License


This project is released under the MIT License. See the [MIT](https://choosealicense.com/licenses/mit/) file for more information.

