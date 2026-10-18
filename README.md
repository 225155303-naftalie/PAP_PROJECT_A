Municipal Financial Management System (MFMS)
PAP521S – Programming in Practice
Project A – Foundation System
Group Members
Student Name	Student Number	Main Responsibility
Student 1	225134497 employee management
Student 2	225009064  Budget Management
Student 3	225150344 Supplier Management
Student 4	225089963 Assets Management
Student 5	224091514 Report
Student 6	225166577 Functions and Integration
Student 7	225155303 Testing and Documentation



What is the MFMS?
The Municipal Financial Management System (MFMS) is a simple C program designed to help a municipality manage important financial and administrative information.



The system helps the municipality manage:
Employees
Department budgets
Suppliers
Municipal assets
Reports

Main Features of the System
1.Employee Management
The system allows the user to:
Add a new employee
Enter the employee's ID, name, department, and salary
View all employees
Search for an employee using their ID
Calculate salary statistics, such as the average, highest, and lowest salary

2.Budget Management
The system allows the user to:
Add a budget for a department
Record the amount spent by a department
View all department budgets
Check if a department has spent more than its allocated budget

3 Supplier Management
The system allows the user to:
Add a new supplier
Record the supplier's ID, name, email, phone number, and town
View all suppliers
Search for a supplier by name

4 Asset Management
The system allows the user to:
Add a new municipal asset
Record the asset's ID, name, type, value, department, and condition
View all assets
Search for an asset using its ID

5 Reports
The system can generate different reports, including:

Employee Report – shows the number of employees and salary information
Budget Report – shows the allocated and spent amounts
Supplier Report – shows the total number of suppliers
Asset Report – shows the total number of assets
Full System Report – combines all the reports into one summary

how we compile:
gcc -std=c99 -c main.c
gcc -std=c99 -c employees.c
gcc -std=c99 -c budget.c
gcc -std=c99 -c suppliers.c
gcc -std=c99 -c assets.c
gcc -std=c99 -c reports.c



gcc -o mfms.exe main.o employees.o budget.o suppliers.o assets.o reports.o utilities.o

mfms.exe

