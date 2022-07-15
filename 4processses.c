
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "helper.h"

int main(void)
{
    time_t t;
    char s[256];
    int i, j;
    pid_t p1, p2, p3, p4, pp;

    struct record data[no_of_records];

    printf("Driver Time: %s\n", ctime(&t));
    p1 = getpid();
    p2 = getpid();
    p3 = getpid();
    p4 = getpid();

    pp = getppid();
    printf("Driver PID: %d   Driver PPID: %d \n", p1, pp);
    p1 = fork();
    p2 = fork();

    clock_t start = clock();

    if (p1 == 0)
    {

        struct record what_to_sort[no_of_records / 4];

        for (size_t i = 0; i < no_of_records / 4; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }

    if (p2 == 0)
    {
        struct record what_to_sort[no_of_records / 2];
        int starting = no_of_records / 4 + 1;

        for (size_t i = starting; i < no_of_records; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }

    if (p3 == 0)
    {
        struct record what_to_sort[no_of_records / (int)(3 / 4)];
        int starting = no_of_records / 2 + 1;

        for (size_t i = starting; i < no_of_records; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }
    if (p4 == 0)
    {
        struct record what_to_sort[no_of_records];
        int starting = no_of_records / 2 + 1;

        for (size_t i = starting; i < no_of_records; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }

    if (pp == 0)
    {
        read_data(data);
    }
    time_t end = clock();
    double time_taken = (double)(end - start);
    printf("The time taken is %f", time_taken);
    exit(0);
}
