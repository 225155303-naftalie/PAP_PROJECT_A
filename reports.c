#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "utilities.h"

void employeeReport(void)
{
    printf("\n=====================================\n");
    printf("EMPLOYEE REPORT\n");
    printf("=====================================\n");
    printf("Total Employees: %d\n", getEmployeeCount());
    printf("Average Salary:  %.2f\n", getAverageSalary());
    printf("Highest Salary:  %.2f\n", getHighestSalary());
    printf("Lowest Salary:   %.2f\n", getLowestSalary());
    printf("=====================================\n");
}

void budgetReport(void)
{
    double allocated = getTotalAllocated();
    double expenditure = getTotalExpenditure();

    printf("\n=====================================\n");
    printf("BUDGET REPORT\n");
    printf("=====================================\n");
    printf("Total Departments: %d\n", getDepartmentCount());
    printf("Total Allocated:   %.2f\n", allocated);
    printf("Total Expenditure: %.2f\n", expenditure);
    printf("Remaining Budget:  %.2f\n", allocated - expenditure);

    if (allocated - expenditure >= 0) {
        printf("Status: WITHIN BUDGET\n");
    } else {
        printf("Status: OVER BUDGET\n");
    }
    printf("=====================================\n");
}

void supplierReport(void)
{
    printf("\n=====================================\n");
    printf("SUPPLIER REPORT\n");
    printf("=====================================\n");
    printf("Total Suppliers: %d\n", getSupplierCount());
    printf("=====================================\n");
}

void assetReport(void)
{
    printf("\n=====================================\n");
    printf("ASSET REPORT\n");
    printf("=====================================\n");
    printf("Total Assets: %d\n", getAssetCount());
    printf("=====================================\n");
}

void fullSystemReport(void)
{
    printf("\n=====================================\n");
    printf("#        FULL SYSTEM REPORT         #\n");
    printf("=====================================\n");

    employeeReport();
    budgetReport();
    supplierReport();
    assetReport();

    printf("\n=====================================\n");
    printf("#        END OF SYSTEM REPORT       #\n");
    printf("=====================================\n");
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