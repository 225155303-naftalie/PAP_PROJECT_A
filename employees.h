#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 35

// Module Navigation & Core Features
void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalaryInfo(void);

// Reporting Engine Getters
int getEmployeeCount(void);
double getAverageSalary(void);
double getHighestSalary(void);
double getLowestSalary(void);

#endif