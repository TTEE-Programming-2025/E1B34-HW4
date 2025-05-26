#include <stdio.h>
#include <stdlib.h>

#define PASSWORD 2025

void showWelcomeScreen() {
    printf("==============================\n");
    printf("    Welcome to Grade System    \n");
    printf("==============================\n");
    for (int i = 0; i < 18; i++) {
        printf("* Line %d: Your style line!\n", i + 1);
    }
    printf("==============================\n");
}

void showMainMenu() {
    printf("------------[Grade System]----------\n");
    printf("|  a. Enter student grades         |\n");
    printf("|  b. Display student grades       |\n");
    printf("|  c. Search for student grades    |\n");
    printf("|  d. Grade ranking                |\n");
    printf("|  e. Exit system                  |\n");
    printf("------------------------------------\n");
    printf("Please select an option: ");
}

int main() {
    int inputPassword, attempts = 0;
    char option;

    showWelcomeScreen();

    while (attempts < 3) {
        printf("Enter the 4-digit password: ");
        scanf("%d", &inputPassword);
        if (inputPassword == PASSWORD) {
            printf("Welcome! Password correct.\n");
            break;
        } else {
            printf("Incorrect password. Try again.\n");
            attempts++;
        }
    }

    if (attempts == 3) {
        printf("Too many incorrect attempts. Exiting program.\n");
        return 0;
    }

    while (1) {
        system("cls");
        showMainMenu();
        scanf(" %c", &option);
        printf("You selected: %c (feature not implemented yet)\n", option);
        system("pause");
    }

    return 0;
}

