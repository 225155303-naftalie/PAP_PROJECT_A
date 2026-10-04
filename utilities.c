#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int readInt(void)
{
    int value;
    char buffer[100];

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &value) == 1) {
                return value;
            }
        }
        printf("Invalid input. Enter a number: ");
    }
}

double readDouble(void)
{
    double value;
    char buffer[100];

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf", &value) == 1) {
                return value;
            }
        }
        printf("Invalid input. Enter a number: ");
    }
}

void readString(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    getchar();
}

void clearScreen(void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}