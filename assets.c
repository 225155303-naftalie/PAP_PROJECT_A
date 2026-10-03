#include <stdio.h>
#include <string.h>
#include "assets.h"

int    assetIDs[MAX];
char   assetNames[MAX][50];
char   assetTypes[MAX][30];
double assetValues[MAX];
char   assetDepts[MAX][50];
char   assetConditions[MAX][20];
int    assetCount = 0;

void assetMenu(void)
{
    int choice;

    do {
        printf("\n===== ASSET MANAGEMENT =====\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset by ID\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAsset();
                break;
            case 2:
                displayAssets();
                break;
            case 3:
                searchAsset();
                break;
            case 4:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    } while (choice != 4);
}

int findAssetByID(int id)
{
    int i;

    for (i = 0; i < assetCount; i++) {
        if (assetIDs[i] == id) {
            return i;
        }
    }
    return -1;
}

void addAsset(void)
{
    int    newID;
    char   newName[50];
    char   newType[30];
    double newValue;
    char   newDept[50];
    char   newCondition[20];

    if (assetCount >= MAX) {
        printf("Asset register is full. Cannot add more.\n");
        return;
    }

    printf("\nEnter Asset ID (positive number): ");
    scanf("%d", &newID);

    while (newID <= 0) {
        printf("Invalid! ID must be positive. Enter again: ");
        scanf("%d", &newID);
    }

    if (findAssetByID(newID) != -1) {
        printf("An asset with ID %d already exists.\n", newID);
        return;
    }

    printf("Enter Asset Name: ");
    scanf(" %[^\n]", newName);

    while (strlen(newName) == 0) {
        printf("Name cannot be empty. Enter again: ");
        scanf(" %[^\n]", newName);
    }

    printf("Enter Asset Type (Vehicle/Computer/Building/Equipment/Furniture): ");
    scanf(" %[^\n]", newType);

    while (strlen(newType) == 0) {
        printf("Type cannot be empty. Enter again: ");
        scanf(" %[^\n]", newType);
    }

    printf("Enter Purchase Value (N$): ");
    scanf("%lf", &newValue);

    while (newValue < 0) {
        printf("Value cannot be negative. Enter again: ");
        scanf("%lf", &newValue);
    }

    printf("Enter Department: ");
    scanf(" %[^\n]", newDept);

    while (strlen(newDept) == 0) {
        printf("Department cannot be empty. Enter again: ");
        scanf(" %[^\n]", newDept);
    }

    printf("Enter Condition (Excellent/Good/Fair/Poor): ");
    scanf(" %[^\n]", newCondition);

    while (strcmp(newCondition, "Excellent") != 0 &&
           strcmp(newCondition, "Good")      != 0 &&
           strcmp(newCondition, "Fair")      != 0 &&
           strcmp(newCondition, "Poor")      != 0) {
        printf("Invalid! Enter Excellent/Good/Fair/Poor: ");
        scanf(" %[^\n]", newCondition);
    }

    assetIDs[assetCount]    = newID;
    assetValues[assetCount] = newValue;
    strcpy(assetNames[assetCount],      newName);
    strcpy(assetTypes[assetCount],      newType);
    strcpy(assetDepts[assetCount],      newDept);
    strcpy(assetConditions[assetCount], newCondition);

    assetCount++;

    printf("\nAsset '%s' (ID: %d) added successfully!\n", newName, newID);
}

void displayAssets(void)
{
    int i;

    if (assetCount == 0) {
        printf("\nNo assets registered yet.\n");
        return;
    }

    printf("\n==================== MUNICIPAL ASSET REGISTER ====================\n");
    printf("%-6s %-20s %-12s %-14s %-15s %-10s\n",
           "ID", "Name", "Type", "Value (N$)", "Department", "Condition");
    printf("-------------------------------------------------------------------\n");

    for (i = 0; i < assetCount; i++) {
        printf("%-6d %-20s %-12s %-14.2f %-15s %-10s\n",
               assetIDs[i],
               assetNames[i],
               assetTypes[i],
               assetValues[i],
               assetDepts[i],
               assetConditions[i]);
    }

    printf("===================================================================\n");
    printf("Total Assets: %d\n", assetCount);
}

void searchAsset(void)
{
    int id;
    int index;

    if (assetCount == 0) {
        printf("\nNo assets to search.\n");
        return;
    }

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &id);

    index = findAssetByID(id);

    if (index == -1) {
        printf("No asset found with ID %d.\n", id);
    } else {
        printf("\n--- ASSET FOUND ---\n");
        printf("ID         : %d\n",    assetIDs[index]);
        printf("Name       : %s\n",    assetNames[index]);
        printf("Type       : %s\n",    assetTypes[index]);
        printf("Value      : N$%.2f\n", assetValues[index]);
        printf("Department : %s\n",    assetDepts[index]);
        printf("Condition  : %s\n",    assetConditions[index]);
    }
}