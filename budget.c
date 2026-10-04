#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utilities.h"

static char departmentNames[MAX_DEPARTMENTS][50];
static double allocatedBudgets[MAX_DEPARTMENTS];
static double expenditures[MAX_DEPARTMENTS];
static int departmentCount = 0;

void addBudget(void)
{
    if (departmentCount >= MAX_DEPARTMENTS) {
        printf("Maximum departments reached.\n");
        return;
    }

    printf("\n--- ADD DEPARTMENT BUDGET ---\n");

    printf("Enter department name: ");
    readString(departmentNames[departmentCount], 50);

    printf("Enter allocated budget: ");
    allocatedBudgets[departmentCount] = readDouble();
    while (allocatedBudgets[departmentCount] < 0) {
        printf("Budget cannot be negative. Enter again: ");
        allocatedBudgets[departmentCount] = readDouble();
    }

    printf("Enter expenditure: ");
    expenditures[departmentCount] = readDouble();
    while (expenditures[departmentCount] < 0) {
        printf("Expenditure cannot be negative. Enter again: ");
        expenditures[departmentCount] = readDouble();
    }

    departmentCount++;
    printf("Budget recorded successfully.\n");
}

void displayBudgets(void)
{
    int i;

    if (departmentCount == 0) {
        printf("No budgets recorded yet.\n");
        return;
    }

    printf("\n--- DEPARTMENT BUDGETS ---\n");
    printf("%-20s %-15s %-15s %-15s %-15s\n",
           "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("--------------------------------------------------\n");

    for (i = 0; i < departmentCount; i++) {
        double remaining = allocatedBudgets[i] - expenditures[i];
        printf("%-20s %-15.2f %-15.2f %-15.2f %-15s\n",
               departmentNames[i],
               allocatedBudgets[i],
               expenditures[i],
               remaining,
               remaining >= 0 ? "WITHIN BUDGET" : "OVER BUDGET");
    }
}

void checkBudgetStatus(void)
{
    int i;
    int overBudget = 0;

    if (departmentCount == 0) {
        printf("No budgets recorded yet.\n");
        return;
    }

    printf("\n--- DEPARTMENTS OVER BUDGET ---\n");
    for (i = 0; i < departmentCount; i++) {
        if (expenditures[i] > allocatedBudgets[i]) {
            printf("%s: Over by %.2f\n",
                   departmentNames[i],
                   expenditures[i] - allocatedBudgets[i]);
            overBudget = 1;
        }
    }

    if (!overBudget) {
        printf("All departments are within budget.\n");
    }
}

int getDepartmentCount(void)
{
    return departmentCount;
}

double getTotalAllocated(void)
{
    int i;
    double total = 0;

    for (i = 0; i < departmentCount; i++) {
        total = total + allocatedBudgets[i];
    }
    return total;
}

double getTotalExpenditure(void)
{
    int i;
    double total = 0;

    for (i = 0; i < departmentCount; i++) {
        total = total + expenditures[i];
    }
    return total;
}