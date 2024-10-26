#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Employee {
    std::string name;
    std::string salary;
    std::string hired_date;
    std::string department;

    public:
        Employee(std::string name, std::string salary, std::string hired_date, std::string department) {
            this->name = name;
            this->salary = salary;
            this->hired_date = hired_date;
            this->department = department;
        }

        std::string get_name() {
            return this->name;
        }
        void set_name(std::string name) {
            this->name = name;
        }

        float get_salary() {
            return std::stof(this->salary);
        }

        void set_salary(std::string new_salary) {
            this->salary = new_salary;
        }

        std::string get_hired_date() {
            return this->hired_date;
        }

        void set_hired_date(std::string new_hired_date) {
            this->hired_date = new_hired_date;
        }

        std::string get_department() {
            return this->department;
        }

        void set_department(std::string new_department) {
            this->department = new_department;
        }
};

class Company {
    std::string name;
    std::string cnpj;
    vector<Employee> employees;

    public:
        Company(std::string name, std::string cnpj) {
            this->name = name;
            this->cnpj = cnpj;
        }

        std::string get_name() {
            return this->name;
        }

        void set_name(std::string name) {
            this->name = name;
        }

        std::string get_cnpj() {
            return this->cnpj;
        }

        void set_cnpj(std::string new_cnpj) {
            this->cnpj = new_cnpj;
        }

        Employee get_employee(std::string name) {
            for (int i = 0; i < employees.size(); i++) {
                if (employees[i].get_name() == name) {
                    return employees[i];
                }
            }
        }

        void set_employee(Employee new_employee) {
            employees.push_back(new_employee);
        }


        void list_employees() {
            std::cout << "| Employees:                                                      |" << std::endl;
            std::cout << "|=================================================================|" << std::endl;
            for (int i = 0; i < employees.size(); i++) {
                    std::cout << "|Name: " << employees[i].get_name() << "  | Salary: " << employees[i].get_salary() << std::endl;
                }
            }

        void increase_salary(std::string department) {
            for (int i = 0; i < employees.size(); i++) {
                if (employees[i].get_department() == department){
                    float current_salary = employees[i].get_salary();
                    float new_salary = current_salary + (current_salary * 10/100);
                    employees[i].set_salary(std::to_string(new_salary));
                }
            }
        }

        void reserve_employee_slots(int num_slots) {
            employees.reserve(num_slots);
        }

};




int main()
{
    std::string company_name, cnpj;
    int employees_quantity;

    std::cout << "|_____________________________________________|" << std::endl;

    std::cout << ">> Provide the name for the company: " << std::endl;
    std::cin >> company_name;

    std::cout << ">> Provide the cnpj for the company: " << std::endl;
    std::cin >> cnpj;

    std::cout << ">> Provide the employees_quantity for the company: " << std::endl;
    std::cin >> employees_quantity;

    Company company_object = Company(company_name, cnpj);
    company_object.reserve_employee_slots(employees_quantity);

    for (int i = 0; i < employees_quantity; i++) {
        std::string employee_name, employee_salary, employee_hired_date, employee_department;
        char answer_to_continue;
        std::cout << "Type the employee name: " << std::endl;
        std::cin >> employee_name;

        std::cout << "Type the employee salary: " << std::endl;
        std::cin >> employee_salary;

        std::cout << "Type the employee hired date: " << std::endl;
        std::cin >> employee_hired_date;

        std::cout << "Type the employee department: " << std::endl;
        std::cin >> employee_department;

        Employee employee_object = Employee(employee_name, employee_salary, employee_hired_date, employee_department);
        company_object.set_employee(employee_object);

        if (i+1 != employees_quantity) {
            std::cout << "Do you want to add one more employee: [y/n]" << std::endl;
            std::cin >> answer_to_continue;

            if (answer_to_continue == 'n') {
                break;
            }

        }

    }

    company_object.increase_salary("TI");
    company_object.list_employees();
}
