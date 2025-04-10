#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, string> record;
vector<string> available_courses = {"B.Tech", "BCA", "BBA", "BSC", "Law", "M.Tech", "B.Com", "GameDev", "AJ_Tech", "Busniess", "CMA", "Digital Marketing", "Accountant"};

class Student{
private:
    string name, rollNo;
    double CGPA;
    string feedback = "";
    vector<string> courses; int maxCourse=0;

public:
    Student(){name = ""; rollNo = ""; CGPA = 0;}

    Student(string name, string rollNo, string course) {
        if (record.find(rollNo) != record.end()) {
            cout << "RollNo must be unique, Student record Not created!";
            return;         
        }

        bool found = false;
        for (auto c : available_courses) { if (c==course) found = true; }

        if (found) { 
            this->courses.push_back(course);
            maxCourse++;
        }
        else {
            cout << "Course Not avaible, Enter a valid course later though Update_Course()\n";
            cout << "Avaible Courses: \n";
            for (auto c : available_courses){
                cout << c << '\n';
            }
        }

        this->name = name;
        this->CGPA = 0.0;
        this->rollNo = rollNo;
        record[rollNo] = name;
        
    }

    Student(const Student& obj){
        this->name = obj.name;
        this->rollNo = obj.rollNo;
        this->CGPA = obj.CGPA;
        this->feedback = obj.feedback;
        this->courses = obj.courses;
        this->maxCourse = obj.maxCourse;
    }


    ~Student() {
        if (!rollNo.empty()) record.erase(rollNo);
    }

    void Update_Course(string course){
        bool found = false;
        for (auto c : available_courses){
            if (c==course) found = true;
        }

        if (found && maxCourse <= 4) {
            this->courses.push_back(course);
            maxCourse++;

            string choice;
            cout << "\nWant to add More Course? (Y:N): ";
            getline(cin>>ws, choice);
            if (choice=="y" || choice == "Y" || choice == "yes" || choice == "YES") {
                string course = "";
                cout << "Enter course: ";
                getline(cin>>ws, course);
                Update_Course(course);
            }
            else{
                cout <<"\nPrevious Record Saved Successfully, Exiting Now....\n";
            }
        }
        else {
            cout << "Course Not Avaible Or Course Limit Reached!\n";
        }

    }

    void Update_CGPA(double CGPA){
        if (CGPA >= 0 && CGPA <= 10) {
            this->CGPA = CGPA;

            if (CGPA <= 5) this->feedback = "Very DUMB STUDENT! Cant DO anything! Black Future!";
            else if (CGPA <= 7 && CGPA > 5) this->feedback = "Average Student! Needs Hardworkkkkkkk!";
            else if (CGPA <= 8 && CGPA > 7) this->feedback = "Great Student! Can even excel if works hard!";
            else this->feedback = "Marvelous Student!";
            
            cout << "CGPA & FeedBack successfully Updated!\n";
        }
    }

    void DisplayInfo() {
        cout << "\n---------- STUDENT INFORMATION ----------\n";
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << CGPA << endl;
        cout << "Feedback: " << feedback << endl;
        cout << "Enrolled Courses (" << maxCourse << "): ";
        if (maxCourse == 0) {
            cout << "No courses enrolled yet!";
        } else {
            for (int i = 0; i < courses.size(); i++) {
                cout << courses[i];
                if (i < courses.size() - 1) cout << ", ";
            }
        }
        cout << "\n----------------------------------------\n";
    }
    
    string GetRollNo() {
        return rollNo;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    StudentManagementSystem() {}
    
    void AddStudent(Student& student) {
        students.push_back(student);
        cout << "Student added to the system successfully!\n";
    }
    
    void SearchStudent(string rollNo) {
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].GetRollNo() == rollNo) {
                cout << "Student found!\n";
                students[i].DisplayInfo();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Student with Roll No " << rollNo << " not found in the system!\n";
        }
    }

    int GetStudentIndex(string rollNo) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].GetRollNo() == rollNo) {
                return i;
            }
        }
        return -1;
    }

    void DisplayStudentDetails(string rollNo) {
        int idx = GetStudentIndex(rollNo);
        if (idx != -1) {
            students[idx].DisplayInfo();
        } else {
            cout << "Student with Roll No " << rollNo << " not found in the system!\n";
        }
    }
    
    void DisplayAllStudents() {
        if (students.size() == 0) {
            cout << "No students in the system yet!\n";
            return;
        }
        
        cout << "\n====== ALL STUDENT RECORDS ======\n";
        for (int i = 0; i < students.size(); i++) {
            students[i].DisplayInfo();
        }
        cout << "================================\n";
    }
    
    void UpdateStudentCGPA(string rollNo, double cgpa) {
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].GetRollNo() == rollNo) {
                students[i].Update_CGPA(cgpa);
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Student with Roll No " << rollNo << " not found in the system!\n";
        }
    }
    
    void UpdateStudentCourse(string rollNo, string course) {
        bool found = false;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].GetRollNo() == rollNo) {
                students[i].Update_Course(course);
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Student with Roll No " << rollNo << " not found in the system!\n";
        }
    }
};

int main(){
    StudentManagementSystem sms;
    
    int choice;
    string name, rollNo, course;
    double cgpa;
    
    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No\n";
        cout << "4. Update Student CGPA\n";
        cout << "5. Add Course to Student\n";
        cout << "6. Display Student Details\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter Student Name: ";
                getline(cin >> ws, name);
                cout << "Enter Roll No: ";
                getline(cin >> ws, rollNo);
                cout << "Enter First Course: ";
                getline(cin >> ws, course);
                {
                    Student newStudent(name, rollNo, course);
                    sms.AddStudent(newStudent);
                }
                break;
                
            case 2:
                sms.DisplayAllStudents();
                break;
                
            case 3:
                cout << "Enter Roll No to search: ";
                getline(cin >> ws, rollNo);
                sms.SearchStudent(rollNo);
                break;
                
            case 4:
                cout << "Enter Roll No: ";
                getline(cin >> ws, rollNo);
                cout << "Enter new CGPA (0-10): ";
                cin >> cgpa;
                sms.UpdateStudentCGPA(rollNo, cgpa);
                break;
                
            case 5:
                cout << "Enter Roll No: ";
                getline(cin >> ws, rollNo);
                cout << "Enter Course to add: ";
                getline(cin >> ws, course);
                sms.UpdateStudentCourse(rollNo, course);
                break;
                
            case 6:
                cout << "Enter Roll No to display details: ";
                getline(cin >> ws, rollNo);
                sms.DisplayStudentDetails(rollNo);
                break;
                
            case 0:
                cout << "Exiting System. Goodbye!\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
    } while (choice != 0);
    
    return 0;
}