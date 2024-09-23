#include <stdio.h>
#include <math.h>

#define G 9.8
#define PI 3.14159265358979323846

// Function to convert degrees to radians
double degToRad(double degrees) {
    return degrees * PI / 180.0;
}

// Function to calculate horizontal positions 
void calculateHorizontalPositions(double* positions, double velocity, double timeStep, int numSteps) {
    for (int step_idx = 0; step_idx < numSteps; step_idx++) {
        double time = step_idx * timeStep;
        *(positions + step_idx) = velocity * time;
    }
}

// Function to calculate vertical positions 
void calculateVerticalPositions(double* positions, double velocity, double timeStep, int numSteps) {
    for (int step_idx = 0; step_idx < numSteps; step_idx++) {
        double time = step_idx * timeStep;
        *(positions + step_idx) = velocity * time - 0.5 * G * time * time;
    }
}

int main(void) {
    double initialVelocity, angleInDegrees, timeStep;
    int numSteps;

    printf("Welcome to the Modified Golf Ball Tracker!\n");

    // Input section
    printf("Enter the initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);

    printf("Enter the angle of projection (degrees): ");
    scanf("%lf", &angleInDegrees);

    printf("Enter the time step (s): ");
    scanf("%lf", &timeStep);

    printf("Enter the number of steps: ");
    scanf("%d", &numSteps);

    // Processing section
    double angleInRadians = degToRad(angleInDegrees);
    double horizontalVelocity = initialVelocity * cos(angleInRadians);
    double verticalVelocity = initialVelocity * sin(angleInRadians);

    double horizontalPositions[numSteps];
    double verticalPositions[numSteps];

    calculateHorizontalPositions(horizontalPositions, horizontalVelocity, timeStep, numSteps);
    calculateVerticalPositions(verticalPositions, verticalVelocity, timeStep, numSteps);

    for (int step_idx = 0; step_idx < numSteps; step_idx++) {
        double time = step_idx * timeStep;

        // Output section
        printf("Time: %.2lf s, Horizontal Displacement: %.2lf m, Vertical Displacement: %.2lf m\n",
            time, *(horizontalPositions + step_idx), *(verticalPositions + step_idx));

        if (*(verticalPositions + step_idx) < 0) {
            printf("Golf ball has touched down!\n");
            break;
        }
    }

    if (*(verticalPositions + numSteps - 1) > 0) {
        printf("Golf ball is still in flight.\n");
    }

    return 0;
}