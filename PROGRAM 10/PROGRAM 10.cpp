



#include <fstream>

#include <iostream>

#include <string>

using namespace std;


struct Student {

    int rollNo;

    string name;

    double marks;

};


int main() {

    ofstream output("students.txt");

    if (!output) {

        cerr << "Unable to open students.txt." << endl;

        return 1;

    }


    output << 101 << " " << "Aarav" << " " << 85.5 << endl;

    output << 102 << " " << "Isha" << " " << 91.0 << endl;

    output.close();


    ifstream input("students.txt");

    Student student;

    cout << "=== Student Records ===" << endl;

    while (input >> student.rollNo >> student.name >> student.marks) {

        cout << student.rollNo << " | " << student.name

             << " | " << student.marks << endl;

    }

}

