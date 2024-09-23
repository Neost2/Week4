#include <stdio.h>
#include <math.h>

#define G 9.8
#define PI 3.14159265358979323846

// Function to convert degrees to radians
double degToRad(double degrees) {
    return degrees * PI / 180.0;
}

int main(void) {
    double initialVelocity, angleInDegrees, timeStep;
    int numSteps;

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

    for (int step_idx = 0; step_idx < numSteps; step_idx++) {
        double time = step_idx * timeStep;
        double horizontalDisplacement = horizontalVelocity * time;
        double verticalDisplacement = verticalVelocity * time - 0.5 * G * time * time;

        // Output section
        printf("Time: %.2lf s, Horizontal Displacement: %.2lf m, Vertical Displacement: %.2lf m\n",
            time, horizontalDisplacement, verticalDisplacement);

        if (verticalDisplacement < 0) {
            printf("Golf ball has touched down!\n");
            break;
        }
        else if (step_idx == numSteps - 1 && verticalDisplacement > 0) {
            printf("Golf ball is still in flight.\n");
        }
    }

    return 0;
}