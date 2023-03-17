#include <stdio.h>
#include "utils.h"
#include "Windows.h"

void* realloc_safe(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        fprintf(stderr, "Warning: memory allocation failed\n");
    }
    return new_ptr;
}


void* realloc_safe_with_retry(void* ptr, size_t size, int retries, int delay) {
    void* new_ptr = NULL;
    for (int i = 0; i < retries; i++) {
        new_ptr = realloc(ptr, size);
        if (new_ptr != NULL) {
            break;
        }
        fprintf(stderr, "Error: memory allocation failed, retrying...\n");
        Sleep(delay); // Wait for 'delay' seconds before retrying
    }
    if (new_ptr == NULL) {
        fprintf(stderr, "Error: memory allocation failed after %d retries\n", retries);
        // Handle the failure, e.g., by returning NULL or a fallback value
    }
    return new_ptr;
}


// Generic function to save data to a binary file
void save_data_to_binary_file(void* data, size_t elem_size, int num_elems, const char* filename) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "wb");
    if (err != 0 || file == NULL) {
        fprintf(stderr, "Error: unable to open file '%s'\n", filename);
        return;
    }

    fwrite(&num_elems, sizeof(int), 1, file);
    fwrite(data, elem_size, num_elems, file);

    fclose(file);
}

// Generic function to load data from a binary file
void* load_data_from_binary_file(size_t elem_size, int* num_elems, const char* filename) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "rb");
    if (err != 0 || file == NULL) {
        fprintf(stderr, "Error: unable to open file '%s'\n", filename);
        return NULL;
    }

    fread(num_elems, sizeof(int), 1, file);

    void* data = malloc(*num_elems * elem_size);
    fread(data, elem_size, *num_elems, file);

    fclose(file);

    return data;
}


// Generic function to save data to a text file using a custom print function
void save_data_to_text_file(void* data, size_t elem_size, int num_elems, const char* filename, void (*print_func)(FILE*, void*)) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL) {
        fprintf(stderr, "Error: unable to open file '%s'\n", filename);
        return;
    }

    fprintf(file, "%d\n", num_elems);
    for (int i = 0; i < num_elems; i++) {
        print_func(file, (char*)data + i * elem_size);
    }

    fclose(file);
}


// Generic function to load data from a text file using a custom scan function
void* load_data_from_text_file(size_t elem_size, int* num_elems, const char* filename, void (*scan_func)(FILE*, void*)) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL) {
        fprintf(stderr, "Error: unable to open file '%s'\n", filename);
        return NULL;
    }

    fscanf_s(file, "%d\n", num_elems);

    void* data = malloc(*num_elems * elem_size);
    for (int i = 0; i < *num_elems; i++) {
        scan_func(file, (char*)data + i * elem_size);
    }

    fclose(file);

    return data;
}
