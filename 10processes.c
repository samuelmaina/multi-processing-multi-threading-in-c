
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
    pid_t p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, pp;

    struct record data[no_of_records];

    printf("Driver Time: %s\n", ctime(&t));
    p1 = getpid();
    p2 = getpid();
    p3 = getpid();
    p4 = getpid();
    p5 = getpid();
    p6 = getpid();
    p7 = getpid();
    p8 = getpid();
    p9 = getpid();
    p10 = getpid();

    pp = getppid();
    printf("Driver PID: %d   Driver PPID: %d \n", p1, pp);
    p1 = fork();
    p2 = fork();

    clock_t start = clock();

    if (p1 == 0)
    {
        int end = no_of_records / 10;
        struct record what_to_sort[end];

        for (size_t i = 0; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }

    if (p2 == 0)
    {
        int end = no_of_records / 5;

        struct record what_to_sort[end];
        int starting = no_of_records / 10 + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }

    if (p3 == 0)
    {
        int end = no_of_records * 3 / 10;
        struct record what_to_sort[end];
        int starting = no_of_records * 5 / 10 + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }
    if (p4 == 0)
    {
        int end = no_of_records * (4 / 10);

        struct record what_to_sort[end];
        int starting = no_of_records / (5 / 3) + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }

    if (p5 == 0)
    {
        int end = no_of_records * (1 / 2);
        struct record what_to_sort[no_of_records];
        int starting = no_of_records * (4 / 5) + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }
    if (p6 == 0)
    {
        int end = no_of_records * (6 / 10);
        struct record what_to_sort[end];
        int starting = no_of_records * (1 / 2) + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }
    if (p7 == 0)
    {
        int end = no_of_records * (7 / 10);
        struct record what_to_sort[end];
        int starting = no_of_records * (3 / 5) + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }
    if (p8 == 0)
    {
        int end = no_of_records * (4 / 5);
        struct record what_to_sort[end];
        int starting = no_of_records * (7 / 8) + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }
    if (p9 == 0)
    {
        int end = no_of_records * (9 / 10);
        struct record what_to_sort[end];
        int starting = no_of_records * (4 / 5) + 1;

        for (size_t i = starting; i < end; i++)
        {
            what_to_sort[i] = data[i];
        }

        bubble_sort(what_to_sort);
    }
    if (p10 == 0)
    {
        struct record what_to_sort[no_of_records];
        int starting = no_of_records * (9 / 10) + 1;

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
