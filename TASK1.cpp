
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


struct Course {
    int courseNumber;
    float grade;
    float creditHours;
    float gradePoints;
};

int main() {
    int numCourses;
    float totalCredits = 0, totalGradePoints = 0;  
    cout << "Enter the number of courses taken: ";
    cin >> numCourses;
    vector<Course> courses;

    
    for (int i = 1; i <= numCourses; ++i) {
        Course c;
        c.courseNumber = i;
        cout << "\nCourse " << i << ":\n";
        cout << "  Enter grade: ";
        cin >> c.grade;
        cout << "  Enter credit hours: ";
        cin >> c.creditHours;

        c.gradePoints = c.grade * c.creditHours;
        totalCredits += c.creditHours;
        totalGradePoints += c.gradePoints;

        courses.push_back(c);
    }

    if (totalCredits == 0) {
        cout << "Error: Total credit hours is zero. Cannot compute CGPA.\n";
        return 1;
    }

    float cgpa = totalGradePoints / totalCredits;
    cout << "\n\n--- Course Summary ---\n";
    cout << fixed << setprecision(2);
    for (const Course& c : courses) {
        cout << "Course " << c.courseNumber 
             << ": Grade = " << c.grade 
             << ", Credit Hours = " << c.creditHours 
             << ", Grade Points = " << c.gradePoints << endl;
    }

    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << cgpa<< endl;

    return 0;
}
