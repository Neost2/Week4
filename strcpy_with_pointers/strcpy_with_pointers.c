#include <stdio.h>
#include <string.h>

#define MAX_INPUT_STRING_SIZE 100

void stringCopy(char* destination_ptr, const char* source_ptr);

int main(void) {
    char source[MAX_INPUT_STRING_SIZE];
    char destination[MAX_INPUT_STRING_SIZE];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    // Remove the trailing newline character from the source string
    if (source[strlen(source) - 1] == '\n') {
        source[strlen(source) - 1] = '\0';
    }

    // Copy the string from source to destination using the custom stringCopy function
    stringCopy(destination, source);

    // Display the original string and the copied string
    printf("Original string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}

/*
 * stringCopy - Copies the null-terminated string from source to destination
 *              using pointer arithmetic.
 *
 * @param destination The pointer to the destination string.
 * @param source      The pointer to the source string.
 */
void stringCopy(char* destination_ptr, const char* source_ptr) {
    // Iterate over the characters in the source string
    while (*source_ptr != '\0') {
        // Copy the current character from source to destination
        *destination_ptr = *source_ptr;

        // Move to the next character in both source and destination
        source_ptr++;
        destination_ptr++;
    }

    // Append the null character to the end of the destination string
    *destination_ptr = '\0';
}