



#include <iostream>

#include <string>

#include <vector>

using namespace std;


class Student {

private:

    int rollNo;

    string name;

    bool present;

public:

    Student(int roll, string studentName)

        : rollNo(roll), name(studentName), present(false) {}

    void markPresent() { present = true; }

    void display() const {

        cout << rollNo << " | " << name

             << " | " << (present ? "Present" : "Absent") << endl;

    }

};


int main() {

    vector<Student> students{

        Student(101, "Aarav"),

        Student(102, "Isha"),

        Student(103, "Kabir")

    };

    students[0].markPresent();

    students[2].markPresent();


    cout << "=== Attendance ===" << endl;

    for (const auto& student : students) {

        student.display();

    }

}

