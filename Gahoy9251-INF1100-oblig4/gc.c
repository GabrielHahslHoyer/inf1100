#include <assert.h>
#include <stdlib.h>
#include "gc.h"

/*
 *      This reference counting garbage collector works by simply storing a
 *      reference count next to the allocated memory in the following way:
 *
 *          [reference count][allocated memory]
 *
 *      When it gets a call to gc_malloc it simply allocates the given size plus
 *      sizeof(int), and whenever it gets a call to gc_register or gc_free it
 *      shifts the address over by the size of an int to inspect the reference
 *      count.
 *
 */

// Allocates a contiguous piece of garbage-collected memory of a certain size
void *gc_malloc(size_t size) {
    // Allocate memory with space for the reference count
    void *allocated = malloc(size + sizeof(int));
    if (allocated == NULL) return NULL; // Check for malloc failure

    // Set the initial reference count to 1
    *(int *)allocated = 1;

    // Return a pointer to the allocated memory (skipping the reference count)
    return (void *)((char *)allocated + sizeof(int));
}

// Registers use of a certain piece of memory. IE takes a pointer to an
// already-allocated piece of memory and increments the reference counter for
// this memory.
void gc_register(void *address) {
    if (address == NULL) return; // Handle null pointer gracefully

    // Shift the address back by sizeof(int) to access the reference count
    address = (char *)address - sizeof(int);
    int *reference_count = (int *)address;

    assert(*reference_count > 0); // Ensure the reference count is positive
    (*reference_count)++; // Increment the reference count
}

// Unregisters use of the memory pointed to by ptr. If the reference counter is
// zero at this point, the memory can be safely freed; otherwise, it must be kept
// intact. 
void gc_free(void *address) {
    if (address == NULL) return; // Handle null pointer gracefully

    // Shift the address back by sizeof(int) to access the reference count
    int *reference_count = (int *)((char *)address - sizeof(int));

    // Decrease the reference count
    assert(*reference_count > 0); // Ensure the reference count is positive
    (*reference_count)--; // Decrement the reference count

    // If the reference count is zero, free the memory
    if (*reference_count == 0) {
        // Free the original memory block, which is the address before shifting
        free(reference_count); // Correctly free the original memory block
    }
}
