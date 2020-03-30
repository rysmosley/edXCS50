// Created by Rebecca Mosley
// March 29, 2020
#include <cs50.h>
#include <stdio.h>

void printRow(int n);

int main(void)
{
 // Ask user how many rows
 int rows = get_int("How many rows?: ");
 printRow(rows);
}

// Print number of rows requested by user
void printRow(int n)
{
    string space = " ";
    string pound = "#";
    string gap = "  ";
    int spaceCount = n - 1;
    int poundCount = n - (n - 1);

    for (int i = 0; i < n; i++)
    {
        // Print first set of spaces
        for (int j = 0; j < spaceCount; j++)
        {
            printf("%s", space);
        }
        
        // Print first set of pounds
        for (int k = 0; k < poundCount; k++)
        {
            printf("%s", pound);
        }

        // Print gap
        printf("%s", gap);

        // Print second set of pounds
        for (int p = 0; p < poundCount; p++)
        {
            printf("%s", pound);
        }

        // Print second set of spaces
        for (int q = 0; q < spaceCount; q++)
        {
            printf("%s", space);
        }

        spaceCount--;
        poundCount++;
        printf("\n");
    }
}
