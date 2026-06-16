#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "ab");

    if (fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(struct Student), 1, fp);

    fclose(fp);

    printf("Student Added Successfully!\n");
}

void viewStudents()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("\n----- STUDENT LIST -----\n");

    while (fread(&s, sizeof(struct Student), 1, fp))
    {
        printf("\nID    : %d", s.id);
        printf("\nName  : %s", s.name);
        printf("\nMarks : %.2f\n", s.marks);
    }

    fclose(fp);
}

void searchStudent()
{
    FILE *fp;
    struct Student s;
    int id, found = 0;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(struct Student), 1, fp))
    {
        if (s.id == id)
        {
            printf("\nStudent Found\n");
            printf("ID    : %d\n", s.id);
            printf("Name  : %s\n", s.name);
            printf("Marks : %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student Not Found!\n");

    fclose(fp);
}

void findTopper()
{
    FILE *fp;
    struct Student s, topper;
    int found = 0;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("No Records Found!\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp))
    {
        if (!found || s.marks > topper.marks)
        {
            topper = s;
            found = 1;
        }
    }

    if (found)
    {
        printf("\n===== TOPPER =====\n");
        printf("ID    : %d\n", topper.id);
        printf("Name  : %s\n", topper.name);
        printf("Marks : %.2f\n", topper.marks);
    }

    fclose(fp);
}