#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 20

void addBudget(void);
void displayBudgets(void);
void checkBudgetStatus(void);

int getDepartmentCount(void);
double getTotalAllocated(void);
double getTotalExpenditure(void);

#endif