#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "utilities.h"

void displayMenu(void)
{
    printf("\n=====================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=====================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");
}

void employeeMenu(void)
{
    int choice;

    do {
        printf("\n--- EMPLOYEE MANAGEMENT ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Salary Statistics\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: calculateSalaryInfo(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

void budgetMenu(void)
{
    int choice;

    do {
        printf("\n--- BUDGET MANAGEMENT ---\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Check Over Budget\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice) {
            case 1: addBudget(); break;
            case 2: displayBudgets(); break;
            case 3: checkBudgetStatus(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

void supplierMenu(void)
{
    int choice;

    do {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice) {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

void assetMenu(void)
{
    int choice;

    do {
        printf("\n--- ASSET MANAGEMENT ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice) {
            case 1: addAsset(); break;
            case 2: displayAssets(); break;
            case 3: searchAsset(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

void reportsMenu(void)
{
    int choice;

    do {
        printf("\n--- REPORTS ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Full System Report\n");
        printf("6. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport(); break;
            case 3: supplierReport(); break;
            case 4: assetReport(); break;
            case 5: fullSystemReport(); break;
            case 6: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
}

int main(void)
{
    int choice;

    printf("=====================================\n");
    printf("Welcome to the\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=====================================\n");

    do {
        displayMenu();
        choice = readInt();

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: budgetMenu(); break;
            case 3: supplierMenu(); break;
            case 4: assetMenu(); break;
            case 5: reportsMenu(); break;
            case 6: printf("Goodbye.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}