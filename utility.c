#include <sys/types.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "helper.h"

void bubble_sort(struct record *data);

void printContent(struct record *data);

void read_data(struct record *);

int main(void)
{

    struct record data[no_of_records];

    // read the data
    read_data(data);

    clock_t start = clock();
    bubble_sort(data);
    clock_t end = clock();

    // print the content of the data array to see that it is indeed sorted.
    printContent(data);

    double time_taken = (double)(end - start);
    printf("%f milliseconds were spent on bubble sorting the data \n", time_taken);
    exit(0);
}

void printContent(struct record *data)
{
    printf("Name \t\t\t\t Number\t\n");
    printf("___________________________________\n");
    for (int i = 0; i < no_of_records; i++)
    {
        printf("%s \t %d\t\n", data[i].name, data[i].no);
    }
}