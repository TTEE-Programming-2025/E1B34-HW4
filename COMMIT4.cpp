#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD 2025
#define MAX_STUDENTS 10

// 定義學生結構
struct Student {
    char name[20];
    int id;
    int math, physics, english;
    float average;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

// 歡迎畫面
void showWelcomeScreen() {
    printf("==============================\n");
    printf("    Welcome to Grade System    \n");
    printf("==============================\n");
    for (int i = 0; i < 18; i++) {
        printf("* Line %d: Your style line!\n", i + 1);
    }
    printf("==============================\n");
}

// 主選單
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

// a 功能：輸入學生資料
void enterStudentGrades() {
    printf("Enter number of students (5-10): ");
    scanf("%d", &studentCount);

    if (studentCount < 5 || studentCount > 10) {
        printf("Invalid number of students.\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", students[i].name);

        printf("Student %d ID (6 digits): ", i + 1);
        scanf("%d", &students[i].id);
        if (students[i].id < 100000 || students[i].id > 999999) {
            printf("Invalid ID. Try again.\n");
            i--;
            continue;
        }

        printf("Math score (0-100): ");
        scanf("%d", &students[i].math);
        if (students[i].math < 0 || students[i].math > 100) {
            printf("Invalid score. Try again.\n");
            i--;
            continue;
        }

        printf("Physics score (0-100): ");
        scanf("%d", &students[i].physics);
        if (students[i].physics < 0 || students[i].physics > 100) {
            printf("Invalid score. Try again.\n");
            i--;
            continue;
        }

        printf("English score (0-100): ");
        scanf("%d", &students[i].english);
        if (students[i].english < 0 || students[i].english > 100) {
            printf("Invalid score. Try again.\n");
            i--;
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
}

// b 功能：顯示所有學生資料
void displayStudentGrades() {
    for (int i = 0; i < studentCount; i++) {
        printf("%s %d Math: %d Physics: %d English: %d Average: %.1f\n",
               students[i].name, students[i].id, students[i].math,
               students[i].physics, students[i].english, students[i].average);
    }
}

// c 功能：搜尋學生資料
void searchStudentGrades() {
    char searchName[20];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Found: %s %d Math: %d Physics: %d English: %d Average: %.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No such student.\n");
    }
}

// d 功能：平均成績排序
int compare(const void *a, const void *b) {
    struct Student *s1 = (struct Student *)a;
    struct Student *s2 = (struct Student *)b;
    if (s2->average > s1->average) return 1;
    else if (s2->average < s1->average) return -1;
    else return 0;
}

void gradeRanking() {
    qsort(students, studentCount, sizeof(struct Student), compare);
    for (int i = 0; i < studentCount; i++) {
        printf("%s %d Average: %.1f\n", students[i].name, students[i].id, students[i].average);
    }
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

        switch (option) {
            case 'a':
                enterStudentGrades();
                break;
            case 'b':
                displayStudentGrades();
                break;
            case 'c':
                searchStudentGrades();
                break;
            case 'd':
                gradeRanking();
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        system("pause");
    }

    return 0;
}

