



#include <iostream>

#include <string>

#include <vector>

using namespace std;


class Employee {

protected:

    int id;

    string name;

    double salary;

public:

    Employee(int employeeId, string employeeName, double employeeSalary)

        : id(employeeId), name(employeeName), salary(employeeSalary) {}

    virtual double calculatePay() const { return salary; }

    virtual void display() const {

        cout << id << " | " << name << " | Pay: Rs. "

             << calculatePay() << endl;

    }

    virtual ~Employee() = default;

};


class Manager : public Employee {

private:

    double bonus;

public:

    Manager(int id, string name, double salary, double managerBonus)

        : Employee(id, name, salary), bonus(managerBonus) {}

    double calculatePay() const override { return salary + bonus; }

};


int main() {

    vector<Employee*> staff;

    staff.push_back(new Employee(1, "Amit", 50000));

    staff.push_back(new Manager(2, "Neha", 70000, 15000));


    for (const auto employee : staff) {

        employee->display();

    }

    for (auto employee : staff) delete employee;

}

