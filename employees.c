#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static int employeeIDs[MAX_EMPLOYEES];
static char employeeNames[MAX_EMPLOYEES][50];
static char employeeDepartments[MAX_EMPLOYEES][50];
static double basicSalaries[MAX_EMPLOYEES];
static double housingAllowances[MAX_EMPLOYEES];
static double transportAllowances[MAX_EMPLOYEES];

static int employeeCount = 0;

void employeeMenu(void)
{
 int choice = 0;

 while (choice != 5) {

 printf("\nEMPLOYEE MANAGEMENT MENU\n");
 printf("1. Add New Employee\n");
 printf("2. Display All Employees\n");
 printf("3. Search Employee by ID\n");
 printf("4. View Salary Statistics\n");
 printf("5. Return to Main Menu\n");
 printf("Enter choice (1-5): ");

 choice = readInt();

 switch (choice) {

 case 1:
 addEmployee();
 break;

 case 2:
 displayEmployees();
 break;

 case 3:
 searchEmployee();
 break;

 case 4:
 calculateSalaryInfo();
 break;

 case 5:
 printf("\nReturning to Main Menu...\n");
 break;

 default:
 printf("\nInvalid option! Please select a choice between 1 and 5.\n");
 }
 }
}
void addEmployee(void)
{
 if (employeeCount >= MAX_EMPLOYEES) {

 printf("\nError: System record capacity reached (%d employees max).\n",
MAX_EMPLOYEES);
 return;
 }
 printf("\nADD NEW EMPLOYEE RECORD\n");
 printf("Enter Employee ID: ");

 int newID = readInt();

 for (int i = 0; i < employeeCount; i++) {
 if (employeeIDs[i] == newID) {
 printf("Error: Employee ID %d already exists! Operation cancelled.\n", newID);
 return;
 }
 }
 employeeIDs[employeeCount] = newID;
 printf("Enter Employee Full Name: ");
 readString(employeeNames[employeeCount], 50);
 printf("Enter Department Name: ");
 readString(employeeDepartments[employeeCount], 50);
 printf("Enter Basic Salary (N$): ");
 double basic = readDouble();
 while (basic < 0) {
 printf("Salary cannot be negative. Re-enter Basic Salary (N$): ");
 basic = readDouble();
 }
 basicSalaries[employeeCount] = basic;
 printf("Enter Housing Allowance (N$): ");
 double housing = readDouble();
 while (housing < 0) {
 printf("Allowance cannot be negative. Re-enter Housing Allowance (N$): ");
 housing = readDouble();
 }
 housingAllowances[employeeCount] = housing;
 printf("Enter Transport Allowance (N$): ");
 double transport = readDouble();
 while (transport < 0) {
 printf("Allowance cannot be negative. Re-enter Transport Allowance (N$): ");
 transport = readDouble();
 }
 transportAllowances[employeeCount] = transport;
 employeeCount++;
 printf("\nEmployee '%s' (ID: %d) successfully added!\n",
 employeeNames[employeeCount - 1], newID);
}
void displayEmployees(void)
{
 if (employeeCount == 0) {
 printf("\nNo employee records found in the database.\n");
 return;
 }
 printf("\nREGISTERED EMPLOYEES\n");
 printf("%-8s %-22s %-18s %-14s %-14s\n", "ID", "Name", "Department", "Basic (N$)", "Gross
(N$)");
 printf("---------------------------------------------------------------------------------\n");
 for (int i = 0; i < employeeCount; i++) {
 double gross = basicSalaries[i] + housingAllowances[i] + transportAllowances[i];
 printf("%-8d %-22s %-18s %-14.2f %-14.2f\n",
 employeeIDs[i],
 employeeNames[i],
 employeeDepartments[i],
 basicSalaries[i],
 gross);
 }
 printf("---------------------------------------------------------------------------------\n");
 printf("Total Records: %d\n", employeeCount);
}
void searchEmployee(void)
{
 if (employeeCount == 0) {
 printf("\nNo employee records available to search.\n");
 return;
 }
 printf("\nEnter Employee ID to search: ");
 int targetID = readInt();

 for (int i = 0; i < employeeCount; i++) {
 if (employeeIDs[i] == targetID) {

 double gross = basicSalaries[i] + housingAllowances[i] + transportAllowances[i];
 printf("\nEMPLOYEE DETAILS\n");

 printf("ID: %d\n", employeeIDs[i]);
 printf("Name: %s\n", employeeNames[i]);
 printf("Department: %s\n", employeeDepartments[i]);
 printf("Basic Salary: N$ %.2f\n", basicSalaries[i]);
 printf("Housing Allowance: N$ %.2f\n", housingAllowances[i]);
 printf("Transport Allowance: N$ %.2f\n", transportAllowances[i]);
 printf("Gross Salary: N$ %.2f\n", gross);
 return;
 }
 }
 printf("\nNo employee record matches ID: %d\n", targetID);
}
void calculateSalaryInfo(void)
{
 if (employeeCount == 0) {
 printf("\nNo employee records available for salary statistics.\n");
 return;
 }
 double total = 0.0;

 double highest = basicSalaries[0];

 double lowest = basicSalaries[0];

 for (int i = 0; i < employeeCount; i++) {

 total += basicSalaries[i];

 if (basicSalaries[i] > highest) highest = basicSalaries[i];
 if (basicSalaries[i] < lowest) lowest = basicSalaries[i];
 }
 printf("\nEMPLOYEE SALARY STATISTICS\n");
 printf("Total Employees: %d\n", employeeCount);
 printf("Average Salary: N$ %.2f\n", total / employeeCount);
 printf("Highest Salary: N$ %.2f\n", highest);
 printf("Lowest Salary: N$ %.2f\n", lowest);
}
int getEmployeeCount(void)
{
 return employeeCount;
}
double getAverageSalary(void)
{
 if (employeeCount == 0) return 0.0;
 double total = 0.0;
 for (int i = 0; i < employeeCount; i++) {
 total += basicSalaries[i];
 }
 return total / employeeCount;
}
double getHighestSalary(void)
{
 if (employeeCount == 0) return 0.0;
 double highest = basicSalaries[0];
 for (int i = 1; i < employeeCount; i++) {
 if (basicSalaries[i] > highest) {
 highest = basicSalaries[i];
 }
 }
 return highest;
}
double getLowestSalary(void)
{
 if (employeeCount == 0) return 0.0;
 double lowest = basicSalaries[0];
 for (int i = 1; i < employeeCount; i++) {
 if (basicSalaries[i] < lowest) {
 lowest = basicSalaries[i];
  }
 }
return lowest;
 }