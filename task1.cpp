#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to convert letter grade to grade point
double getGradePoint(char grade) {
    switch (toupper(grade)) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<char> grades(numCourses);
    vector<int> creditHours(numCourses);
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter letter grade for course " << i + 1 << " (A, B, C, D, F): ";
        cin >> grades[i];
        double gradePoint = getGradePoint(grades[i]);

        while (gradePoint == -1.0) {
            cout << "Invalid grade. Please enter A, B, C, D, or F: ";
            cin >> grades[i];
            gradePoint = getGradePoint(grades[i]);
        }

        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> creditHours[i];

        totalGradePoints += gradePoint * creditHours[i];
        totalCredits += creditHours[i];
    }

    double cgpa = (totalCredits > 0) ? totalGradePoints / totalCredits : 0.0;

    cout << fixed << setprecision(2);
    cout << "\nCourse Details:\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ": Grade = " << grades[i]
             << ", Credit Hours = " << creditHours[i] << endl;
    }

    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
