#include <stdio.h>

#define SIZE 5

void convertCelsiusToFahrenheit(double* temperatures, int size);
void convertCelsiusToKelvin(double* temperatures, int size);

int main(void) {
    double temperatures[SIZE];

    // Input Celsius temperatures from the user
    printf("Enter %d temperature values in Celsius:\n", SIZE);
    for (int temp_array_idx = 0; temp_array_idx < SIZE; temp_array_idx++) {
        scanf("%lf", &temperatures[temp_array_idx]);
    }

    // Display the original Celsius temperatures
    printf("\nOriginal temperatures in Celsius:\n");
    for (int temp_array_idx = 0; temp_array_idx < SIZE; temp_array_idx++) {
        printf("%.2lf ", temperatures[temp_array_idx]);
    }
    printf("\n");

    // Create a copy of the temperatures array for Fahrenheit conversion
    double temperaturesFahrenheit[SIZE];
    for (int temp_array_idx = 0; temp_array_idx < SIZE; temp_array_idx++) {
        temperaturesFahrenheit[temp_array_idx] = temperatures[temp_array_idx];
    }

    // Convert Celsius to Fahrenheit using pointer arithmetic
    convertCelsiusToFahrenheit(temperaturesFahrenheit, SIZE);
    printf("\nTemperatures converted to Fahrenheit:\n");
    for (int temp_array_idx = 0; temp_array_idx < SIZE; temp_array_idx++) {
        printf("%.2lf ", temperaturesFahrenheit[temp_array_idx]);
    }
    printf("\n");

    // Convert Celsius to Kelvin using pointer arithmetic
    convertCelsiusToKelvin(temperatures, SIZE);
    printf("\nTemperatures converted to Kelvin:\n");
    for (int temp_array_idx = 0; temp_array_idx < SIZE; temp_array_idx++) {
        printf("%.2lf ", temperatures[temp_array_idx]);
    }
    printf("\n");

    return 0;
}

/*
 * Converts an array of Celsius temperatures to Fahrenheit using pointer arithmetic.
 *
 * @param temperatures The array of temperatures in Celsius.
 * @param size The size of the temperatures array.
 */
void convertCelsiusToFahrenheit(double* temperatures, int size) {
    double* temp_ptr = temperatures;
    for (int temp_array_idx = 0; temp_array_idx < size; temp_array_idx++) {
        *temp_ptr = (*temp_ptr * 9 / 5) + 32;
        temp_ptr++;
    }
}

/*
 * Converts an array of Celsius temperatures to Kelvin using pointer arithmetic.
 *
 * @param temperatures The array of temperatures in Celsius.
 * @param size The size of the temperatures array.
 */
void convertCelsiusToKelvin(double* temperatures, int size) {
    double* temp_ptr = temperatures;
    double* end_ptr = temperatures + size;
    while (temp_ptr < end_ptr) {
        *temp_ptr += 273.15;
        temp_ptr++;
    }
}