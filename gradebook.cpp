#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_STUDENTS = 100;

void inputStudents(string names[], int grades[], int &count);
void sortGrades(string names[], int grades[], int count, bool ascending);
int searchStudent(string names[], int count, string searchName);
void calculateStatistics(int grades[], int count, double &average, int &highest, int &lowest);
void displayData(string names[], int grades[], int count);
char getLetterGrade(int grade);
void editGrade(string names[], int grades[], int count);

int main() {
string names[MAX_STUDENTS];
int grades[MAX_STUDENTS];
int count = 0;

inputStudents(names, grades, count);

char sortOrder;
cout << "Sort grades in ascending or descending order? (a/d): ";
cin >> sortOrder;
bool ascending = (sortOrder == 'a' || sortOrder == 'A');
sortGrades(names, grades, count, ascending);

cout << "\nSorted Grades:\n";
displayData(names, grades, count);

// Search
string searchName;
cout << "\nEnter student name to search: ";
cin.ignore();
getline(cin, searchName);
int index = searchStudent(names, count, searchName);
if (index != -1)
cout << names[index] << "'s grade: " << grades[index] << " (" << getLetterGrade(grades[index]) << ")" << endl;
else
cout << "Student not found.\n";

char choice;
cout << "\nDo you want to edit a student’s grade? (y/n): ";
cin >> choice;
if (choice == 'y' || choice == 'Y') {
editGrade(names, grades, count);
}

double average;
int highest, lowest;
calculateStatistics(grades, count, average, highest, lowest);

cout << fixed << setprecision(1);
cout << "\nClass Statistics:\n";
cout << "Average Grade: " << average << endl;
cout << "Highest Grade: " << highest << " (" << getLetterGrade(highest) << ")" << endl;
cout << "Lowest Grade: " << lowest << " (" << getLetterGrade(lowest) << ")" << endl;

return 0;
}

void inputStudents(string names[], int grades[], int &count) {
cout << "Enter the number of students: ";
cin >> count;

for (int i = 0; i < count; ++i) {
cout << "Enter student name: ";
cin.ignore();
getline(cin, names[i]);

cout << "Enter " << names[i] << "'s grade: ";
cin >> grades[i];
}
}

void sortGrades(string names[], int grades[], int count, bool ascending) {
for (int i = 0; i < count - 1; ++i) {
for (int j = i + 1; j < count; ++j) {
bool condition = ascending ? (grades[i] > grades[j]) : (grades[i] < grades[j]);
if (condition) {
swap(grades[i], grades[j]);
swap(names[i], names[j]);
}
}
}
}

int searchStudent(string names[], int count, string searchName) {
for (int i = 0; i < count; ++i) {
if (names[i] == searchName) {
return i;
}
}
return -1;
}

void calculateStatistics(int grades[], int count, double &average, int &highest, int &lowest) {
int sum = 0;
highest = grades[0];
lowest = grades[0];

for (int i = 0; i < count; ++i) {
sum += grades[i];
if (grades[i] > highest) highest = grades[i];
if (grades[i] < lowest) lowest = grades[i];
}

average = static_cast<double>(sum) / count;
}

void displayData(string names[], int grades[], int count) {
for (int i = 0; i < count; ++i) {
cout << names[i] << ": " << grades[i] << " (" << getLetterGrade(grades[i]) << ")" << endl;
}
}

char getLetterGrade(int grade) {
if (grade >= 90) return 'A';
if (grade >= 80) return 'B';
if (grade >= 70) return 'C';
if (grade >= 60) return 'D';
return 'F';
}

void editGrade(string names[], int grades[], int count) {
string name;
cout << "Enter student name to edit: ";
cin.ignore();
getline(cin, name);
int index = searchStudent(names, count, name);
if (index != -1) {
cout << "Current grade for " << names[index] << ": " << grades[index] << endl;
cout << "Enter new grade: ";
cin >> grades[index];
cout << "Grade updated.\n";
} else {
cout << "Student not found.\n";
}
}