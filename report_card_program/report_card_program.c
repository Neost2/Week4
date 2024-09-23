#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_GRADES 10

// Function to assign a letter grade based on the average score
char getLetterGrade(double average) {
    switch ((int)average / 10) {
    case 10:
    case 9:
        return 'A';
    case 8:
        return 'B';
    case 7:
        return 'C';
    case 6:
        return 'D';
    default:
        return 'F';
    }
}

int main(void) {
    // Array declaration and initialization
    const int scores[NUM_STUDENTS][NUM_GRADES] = {
        {85, 90, 92, 88, 95, 87, 91, 83, 89, 94},
        {78, 82, 80, 85, 70, 68, 74, 79, 81, 76},
        {92, 89, 95, 91, 93, 87, 90, 92, 88, 96},
        {75, 68, 62, 70, 65, 61, 69, 67, 63, 64},
        {88, 91, 87, 93, 90, 92, 85, 89, 94, 90}
    };

    // Print the grading scale
    printf("Grading Scale:\n");
    printf("A: 90-100\n");
    printf("B: 80-89\n");
    printf("C: 70-79\n");
    printf("D: 60-69\n");
    printf("F: below 60\n\n");

    // Calculating average scores and assigning letter grades
    double class_sum = 0;
    int min_exam_grade = scores[0][NUM_GRADES - 1];
    int max_exam_grade = scores[0][NUM_GRADES - 1];
    int max_student_index = 0;

    for (int student_idx = 0; student_idx < NUM_STUDENTS; student_idx++) {
        int student_sum = 0;
        for (int grade_idx = 0; grade_idx < NUM_GRADES; grade_idx++) {
            student_sum += scores[student_idx][grade_idx];
        }
        double average = (double)student_sum / NUM_GRADES;
        char letter_grade = getLetterGrade(average);
        printf("Student %d - Average score: %.2f, Letter Grade: %c\n", student_idx + 1, average, letter_grade);
        class_sum += average;

        // Update min and max exam grades
        int exam_grade = scores[student_idx][NUM_GRADES - 1];
        if (exam_grade < min_exam_grade) {
            min_exam_grade = exam_grade;
        }
        if (exam_grade > max_exam_grade) {
            max_exam_grade = exam_grade;
            max_student_index = student_idx;
        }
    }

    double class_average = class_sum / NUM_STUDENTS;
    printf("\nClass Average Score: %.2f\n", class_average);
    printf("Student %d had the highest final exam grade: %d\n", max_student_index + 1, max_exam_grade);
    printf("The lowest final exam grade: %d\n", min_exam_grade);

    return 0;
}