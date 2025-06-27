#include <iostream>
#include <vector>

using namespace std;

// Employee class definition
class Employee
{
public:
    Employee(string name, int id, string address, double wage);
    virtual ~Employee();

    void setName(string name);
    void setId(int id);
    void setAddress(string address);
    void setWage(double wage);

    string getName() const;
    int getId() const;
    string getAddress() const;
    double getWage() const;
    virtual double getSalary() const = 0;

private:
    string name;
    int id;
    string address;
    double wage;
};

// HourlyEmployee class definition
class HourlyEmployee : public Employee
{
public:
    HourlyEmployee(string name, int id, string address, double wage, double hours);
    virtual ~HourlyEmployee();

    void setHours(double hours);

    double getHours() const;
    virtual double getSalary() const;

private:
    double hours;
};

// SalariedEmployee class definition
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(string name, int id, string address, double salary);
    virtual ~SalariedEmployee();

    void setSalary(double salary);

    virtual double getSalary() const;

private:
    double salary;
};

// Payroll class definition
class Payroll
{
public:
    Payroll();
    virtual ~Payroll();

    void addEmployee(Employee *employee);
    void removeEmployee(int id);
    void modifyEmployee(int id);
    void printReport();

private:
    vector<Employee *> employees;
};

// Employee class implementation
Employee::Employee(string name, int id, string address, double wage) : name(name), id(id), address(address), wage(wage) {}

Employee::~Employee() {}

void Employee::setName(string name)
{
    this->name = name;
}

void Employee::setId(int id)
{
    this->id = id;
}

void Employee::setAddress(string address)
{
    this->address = address;
}

void Employee::setWage(double wage)
{
    this->wage = wage;
}

string Employee::getName() const
{
    return name;
}

int Employee::getId() const
{
    return id;
}

string Employee::getAddress() const
{
    return address;
}

double Employee::getWage() const
{
    return wage;
}

// HourlyEmployee class implementation
HourlyEmployee::HourlyEmployee(string name, int id, string address, double wage, double hours) : Employee(name, id, address, wage), hours(hours) {}

HourlyEmployee::~HourlyEmployee() {}

void HourlyEmployee::setHours(double hours)
{
    this->hours = hours;
}

double HourlyEmployee::getHours() const
{
    return hours;
}

double HourlyEmployee::getSalary() const
{
    return getWage() * getHours();
}

// SalariedEmployee class implementation
// SalariedEmployee::SalariedEmployee(string name, int id, string address, double salary) :
//     Employee(name, id, address, 0), salary(salary) {}

// SalariedEmployee::~S

SalariedEmployee::SalariedEmployee(string name, int id, string address, double salary) : Employee(name, id, address, 0), salary(salary) {}

SalariedEmployee::~SalariedEmployee() {}

void SalariedEmployee::setSalary(double salary)
{
    this->salary = salary;
}

double SalariedEmployee::getSalary() const
{
    return salary;
}

// Payroll class implementation
Payroll::Payroll() {}

Payroll::~Payroll()
{
    for (int i = 0; i < employees.size(); i++)
    {
        delete employees[i];
    }
}

void Payroll::addEmployee(Employee *employee)
{
    employees.push_back(employee);
}

void Payroll::removeEmployee(int id)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i]->getId() == id)
        {
            delete employees[i];
            employees.erase(employees.begin() + i);
            break;
        }
    }
}

void Payroll::modifyEmployee(int id)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i]->getId() == id)
        {
            string name, address;
            double wage, hours, salary;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter address: ";
            cin >> address;
            if (dynamic_cast<HourlyEmployee *>(employees[i]))
            {
                cout << "Enter hourly wage: ";
                cin >> wage;
                cout << "Enter hours worked: ";
                cin >> hours;
                employees[i]->setName(name);
                employees[i]->setAddress(address);
                dynamic_cast<HourlyEmployee *>(employees[i])->setWage(wage);
                dynamic_cast<HourlyEmployee *>(employees[i])->setHours(hours);
            }
            else if (dynamic_cast<SalariedEmployee *>(employees[i]))
            {
                cout << "Enter annual salary: ";
                cin >> salary;
                employees[i]->setName(name);
                employees[i]->setAddress(address);
                dynamic_cast<SalariedEmployee *>(employees[i])->setSalary(salary);
            }
            break;
        }
    }
}

void Payroll::printReport()
{
    double totalSalary = 0;
    cout << "\t\t\t------salary slip-------" << endl;
    cout << endl;
    cout << "Employee Name\tEmployee ID\tEmployee Address\tEmployee Salary" << endl;
    cout << endl;
    for (int i = 0; i < employees.size(); i++)
    {
        cout << employees[i]->getName() << "\t" << employees[i]->getId() << "\t\t" << employees[i]->getAddress() << "\t\t";
        double salary = employees[i]->getSalary();
        cout << salary << endl;
        totalSalary += salary;
    }
    cout << endl;
    cout << "Total Salary to be given to employees: " << totalSalary << endl;
    cout << "-------created by Ishii------" << endl;
}

// Main function
int main()
{
    Payroll payroll;
    int choice;
    do
    {
        cout << endl;
        cout << "-------Payroll Management System-------" << endl;
        cout << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Remove Employee" << endl;
        cout << "3. Modify Employee" << endl;
        cout << "4. Print Report" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string name, address;
            int id;
            double wage, hours, salary;
            char type;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter address: ";
            cin >> address;
            cout << "Enter employee type (h for hourly, s for salaried): ";
            cin >> type;
            if (type == 'h')
            {
                cout << "Enter hourly wage: ";
                cin >> wage;
                cout << "Enter hours worked: ";
                cin >> hours;
                payroll.addEmployee(new HourlyEmployee(name, id, address, wage, hours));
            }
            else if (type == 's')
            {
                cout << "Enter annual salary: ";
                cin >> salary;
                payroll.addEmployee(new SalariedEmployee(name, id, address, salary));
            }
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            payroll.removeEmployee(id);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            payroll.modifyEmployee(id);
            break;
        }
        case 4:
            payroll.printReport();
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}