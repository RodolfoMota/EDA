// Manager.h
#ifndef MANAGER_H
#define MANAGER_H

// Define the Manager structure
typedef struct {
    int id;
    char name[100];
    char position[100];
} Manager;

// Functions
void add_manager(Manager** managers, int* num_managers, Manager new_manager);
void remove_manager(Manager** managers, int* num_managers, int id);
void update_manager(Manager* managers, int num_managers, Manager updated_manager);
Manager* find_manager(Manager* managers, int num_managers, int id);
void manager_to_string(Manager* manager, char* str);
void string_to_manager(FILE* file, Manager* manager);
#endif // MANAGER_H