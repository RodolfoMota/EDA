// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

/**
 * @file Utils.h
 * @brief Contains utility functions for memory management and file I/O.
 */

 /**
  * @brief Safely reallocates memory.
  */
void* realloc_safe(void* ptr, size_t size);

/**
 * @brief Safely allocates memory.
 */
void* malloc_safe(size_t size);

/**
 * @brief Safely reallocates memory with retry functionality.
 */
void* realloc_safe_with_retry(void* ptr, size_t size, int retries, int delay);

/**
 * @brief Saves data to a binary file.
 */
void save_data_to_binary_file(void* data, size_t elem_size, int num_elems, const char* filename);

/**
 * @brief Loads data from a binary file.
 */
void* load_data_from_binary_file(size_t elem_size, int* num_elems, const char* filename);

/**
 * @brief Saves data to a text file.
 */
void save_data_to_text_file(void* data, size_t elem_size, int num_elems, const char* filename, void (*print_func)(FILE*, void*));

/**
 * @brief Loads data from a text file.
 */
void* load_data_from_text_file(size_t elem_size, int* num_elems, const char* filename, void (*scan_func)(FILE*, void*));

/**
 * @brief Initializes a data file.
 */
void initialize_data_file(const char* filename);

#endif // UTILS_H
