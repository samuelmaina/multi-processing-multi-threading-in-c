#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>
#include "helper.h"
#define MAX 5000000

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

int total = 0;
pthread_mutex_t mutex;
int partition;

FILE *fp;

/*
 *creates arrays of pthreads and an array that holds the number pthread created and starts working on the section of s1 each thread works on concurrently
 */
void solve_threaded()
{
    pthread_t threads[NUM_THREADS];
    int thread_num[NUM_THREADS];
    int i;
    struct record data[no_of_records];

    // create and launch all the threads
    for (i = 0; i < NUM_THREADS; ++i)
    {
        thread_num[i] = i;

        if (pthread_create(&(threads[i]), NULL, bubble_sort, (void *)&thread_num[i]))
        {
            printf("ERROR: Thread creation failed\n");
            exit(EXIT_FAILURE);
        }
        read_data(data);
    }

    // thread completion - waiting for each thread to finish
    for (i = 0; i < NUM_THREADS; ++i)
    {
        if (pthread_join(threads[i], NULL))
        {
            printf("ERROR: Thread joining failed\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error: You must pass in the datafile as a commandline parameter\n");
    }

    readf(argv[1]);

    struct timeval start, end;
    float mtime;
    int secs, usecs;

    pthread_mutex_init(&mutex, NULL);
    gettimeofday(&start, NULL);
    solve_threaded();
    gettimeofday(&end, NULL);
    pthread_mutex_destroy(&mutex);

    secs = end.tv_sec - start.tv_sec;
    usecs = end.tv_usec - start.tv_usec;
    mtime = ((secs)*1000 + usecs / 1000.0) + 0.5;

    printf("The number of substrings is : %d\n", total);
    printf("Elapsed time is : %f milliseconds\n", mtime);

    return 0;
}
