#include <stdio.h>
#include "utils.h"
#include "Windows.h"
/**

@file utils.h
@brief Contains utility functions used in the program.
*/



/**
 * @brief Safely reallocates memory block pointed to by ptr to new size.
 * @param ptr Pointer to memory block to reallocate.
 * @param size New size of memory block in bytes.
 * @return Pointer to reallocated memory block.
 */
void* realloc_safe(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        fprintf(stderr, "Warning: memory allocation failed\n");
    }
    return new_ptr;
}

/**
 * @brief Safely allocates memory block of specified size.
 * @param size Size of memory block in bytes.
 * @return Pointer to allocated memory block.
 * @throws EXIT_FAILURE if memory allocation fails.
 */
void* malloc_safe(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/**
 * @brief Safely reallocates memory block pointed to by ptr to new size with retries and delay.
 * @param ptr Pointer to memory block to reallocate.
 * @param size New size of memory block in bytes.
 * @param retries Number of retries if memory allocation fails.
 * @param delay Delay between retries in seconds.
 * @return Pointer to reallocated memory block.
 */
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


/**
 * @brief Saves data to a binary file.
 * @param data Pointer to data to save.
 * @param elem_size Size of each element in bytes.
 * @param num_elems Number of elements to save.
 * @param filename Name of file to save data to.
 */
void save_data_to_binary_file(void* data, size_t elem_size, int num_elems, const char* filename) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "wb");
    if (err != 0 || file == NULL) {
        fprintf(stderr, "Error: unable to open file '%s'\n", filename);
        return;
    }

    // Add a print statement to check the number of elements being saved to the file
    printf("Saving data to file '%s': %d elements\n", filename, num_elems);

    fwrite(&num_elems, sizeof(int), 1, file);
    fwrite(data, elem_size, num_elems, file);

    fclose(file);
}

/**
 * @brief Loads data from a binary file.
 * @param elem_size Size of each element in bytes.
 * @param num_elems Pointer to variable to store the number of elements read.
 * @param filename Name of file to load data from.
 * @return Pointer to data loaded from file.
 */
void* load_data_from_binary_file(size_t elem_size, int* num_elems, const char* filename) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "rb");

    if (err != 0 || file == NULL) {
        fprintf(stderr, "Warning: unable to open file '%s'. It may not exist.\n", filename);
        *num_elems = 0;
        return NULL;
    }

    fread(num_elems, sizeof(int), 1, file);

    // Add a print statement to check the number of elements read from the file
    printf("Loading data from file '%s': %d elements\n", filename, *num_elems);

    void* data = malloc_safe(*num_elems * elem_size);
    fread(data, elem_size, *num_elems, file);

    fclose(file);

    return data;
}


/**
@brief Saves data to a text file using a custom print function.
@param data Pointer to the data to be saved.
@param elem_size Size of each element in the data array.
@param num_elems Number of elements in the data array.
@param filename Name of the file to which the data will be saved.
@param print_func Pointer to a custom print function that takes a FILE* and a void* as arguments and prints a single element of the data array.
*/
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


/**

@brief Loads data from a text file using a custom scan function.
@param elem_size Size of each element in the data array.
@param num_elems Pointer to an integer where the number of elements in the data array will be stored.
@param filename Name of the file from which the data will be loaded.
@param scan_func Pointer to a custom scan function that takes a FILE* and a void* as arguments and scans a single element of the data array.
@return Pointer to the data array containing the loaded data.
*/
void* load_data_from_text_file(size_t elem_size, int* num_elems, const char* filename, void (*scan_func)(FILE*, void*)) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL) {
        fprintf(stderr, "Error: unable to open file '%s'\n", filename);
        return NULL;
    }

    fscanf_s(file, "%d\n", num_elems);

    void* data = malloc_safe(*num_elems * elem_size);
    for (int i = 0; i < *num_elems; i++) {
        scan_func(file, (char*)data + i * elem_size);
    }

    fclose(file);

    return data;
}

/**

@brief Initializes a new binary data file with zero elements.
@param filename Name of the file to be created.
*/
void initialize_data_file(const char* filename) {
    FILE* file;
    errno_t err = fopen_s(&file, filename, "wb");

    if (err != 0 || file == NULL) {
        fprintf(stderr, "Error: unable to create file '%s'\n", filename);
        return;
    }

    int num_elems = 0;
    fwrite(&num_elems, sizeof(int), 1, file); // Write zero as the number of elements

    fclose(file);
}

