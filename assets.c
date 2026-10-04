#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"

static int assetIDs[MAX_ASSETS];
static char assetNames[MAX_ASSETS][100];
static char assetTypes[MAX_ASSETS][50];
static double assetValues[MAX_ASSETS];
static char assetDepartments[MAX_ASSETS][50];
static char assetConditions[MAX_ASSETS][30];
static int assetCount = 0;

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS) {
        printf("Maximum assets reached.\n");
        return;
    }

    printf("\n--- ADD ASSET ---\n");

    printf("Enter asset ID: ");
    assetIDs[assetCount] = readInt();

    printf("Enter asset name: ");
    readString(assetNames[assetCount], 100);

    printf("Enter asset type: ");
    readString(assetTypes[assetCount], 50);

    printf("Enter purchase value: ");
    assetValues[assetCount] = readDouble();
    while (assetValues[assetCount] < 0) {
        printf("Value cannot be negative. Enter again: ");
        assetValues[assetCount] = readDouble();
    }

    printf("Enter department: ");
    readString(assetDepartments[assetCount], 50);

    printf("Enter condition: ");
    readString(assetConditions[assetCount], 30);

    assetCount++;
    printf("Asset added successfully.\n");
}

void displayAssets(void)
{
    int i;

    if (assetCount == 0) {
        printf("No assets recorded yet.\n");
        return;
    }

    printf("\n--- ASSET REGISTER ---\n");
    printf("%-6s %-20s %-12s %-12s %-15s %-12s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("=====================================\n");

    for (i = 0; i < assetCount; i++) {
        printf("%-6d %-20s %-12s %-12.2f %-15s %-12s\n",
               assetIDs[i],
               assetNames[i],
               assetTypes[i],
               assetValues[i],
               assetDepartments[i],
               assetConditions[i]);
    }
}

void searchAsset(void)
{
    int id;
    int i;
    int found = 0;

    if (assetCount == 0) {
        printf("No assets to search.\n");
        return;
    }

    printf("Enter asset ID to search: ");
    id = readInt();

    for (i = 0; i < assetCount; i++) {
        if (assetIDs[i] == id) {
            printf("\n--- ASSET FOUND ---\n");
            printf("ID:         %d\n", assetIDs[i]);
            printf("Name:       %s\n", assetNames[i]);
            printf("Type:       %s\n", assetTypes[i]);
            printf("Value:      %.2f\n", assetValues[i]);
            printf("Department: %s\n", assetDepartments[i]);
            printf("Condition:  %s\n", assetConditions[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Asset not found.\n");
    }
}

int getAssetCount(void)
{
    return assetCount;
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