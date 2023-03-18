#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

void* realloc_safe(void* ptr, size_t size);

void* malloc_safe(size_t size);

void* realloc_safe_with_retry(void* ptr, size_t size, int retries, int delay);

void save_data_to_binary_file(void* data, size_t elem_size, int num_elems, const char* filename);

void* load_data_from_binary_file(size_t elem_size, int* num_elems, const char* filename);

void save_data_to_text_file(void* data, size_t elem_size, int num_elems, const char* filename, void (*print_func)(FILE*, void*));

void* load_data_from_text_file(size_t elem_size, int* num_elems, const char* filename, void (*scan_func)(FILE*, void*));

void initialize_data_file(const char* filename);

#endif // UTILS_H