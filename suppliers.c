#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"

static int supplierIDs[MAX_SUPPLIERS];
static char supplierNames[MAX_SUPPLIERS][100];
static char supplierEmails[MAX_SUPPLIERS][100];
static char supplierPhones[MAX_SUPPLIERS][30];
static char supplierTowns[MAX_SUPPLIERS][50];
static int supplierCount = 0;

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Maximum suppliers reached.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    printf("Enter supplier ID: ");
    supplierIDs[supplierCount] = readInt();

    printf("Enter supplier name: ");
    readString(supplierNames[supplierCount], 100);

    printf("Enter email: ");
    readString(supplierEmails[supplierCount], 100);

    printf("Enter phone: ");
    readString(supplierPhones[supplierCount], 30);

    printf("Enter town: ");
    readString(supplierTowns[supplierCount], 50);

    supplierCount++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0) {
        printf("No suppliers recorded yet.\n");
        return;
    }

    printf("\n--- SUPPLIER LIST ---\n");
    printf("%-6s %-25s %-25s %-15s %-15s\n",
           "ID", "Name", "Email", "Phone", "Town");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < supplierCount; i++) {
        printf("%-6d %-25s %-25s %-15s %-15s\n",
               supplierIDs[i],
               supplierNames[i],
               supplierEmails[i],
               supplierPhones[i],
               supplierTowns[i]);
    }
}

void searchSupplier(void)
{
    char searchName[100];
    int i;
    int found = 0;

    if (supplierCount == 0) {
        printf("No suppliers to search.\n");
        return;
    }

    printf("Enter supplier name to search: ");
    readString(searchName, 100);

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(supplierNames[i], searchName) == 0) {
            printf("\n--- SUPPLIER FOUND ---\n");
            printf("ID:    %d\n", supplierIDs[i]);
            printf("Name:  %s\n", supplierNames[i]);
            printf("Email: %s\n", supplierEmails[i]);
            printf("Phone: %s\n", supplierPhones[i]);
            printf("Town:  %s\n", supplierTowns[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Supplier not found.\n");
    }
}

int getSupplierCount(void)
{
    return supplierCount;
}