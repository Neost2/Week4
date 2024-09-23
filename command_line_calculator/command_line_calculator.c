#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    // Check if the number of command line arguments is correct
    if (argc != 4) {
        printf("Usage: %s <operand1> <operator> <operand2>\n", argv[0]);
        return 1;
    }

    // Convert the operand strings to integers
    int operand1 = atoi(argv[1]);
    char operator = argv[2][0];
    int operand2 = atoi(argv[3]);
    int result;

    // Perform the arithmetic operation based on the operator
    switch (operator) {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        result = operand1 / operand2;
        break;
    default:
        printf("Invalid operator\n");
        return 1;
    }

    // Display the result
    printf("Result: %d\n", result);

    return 0;

}