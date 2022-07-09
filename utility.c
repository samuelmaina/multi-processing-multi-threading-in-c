#include <sys/types.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// sttucture to store the name and the number of each record in the data.csv file
struct record
{
    char *name;
    int no;
};

const int no_of_records = 10000;

int main(void)
{

    struct record data[no_of_records];

    clock_t start = clock();
    bubble_sort(data);
    clock_t end = clock();

    // read the data
    read_data(data);
}

void read_data(struct record *data)
{

    FILE *fp = fopen("data.csv", "r");
    if (!fp)
        printf("Can't open the file");
    else
    {
        char buffer[1024];

        int row = 0;
        int column = 0, index = 0;

        while (fgets(buffer,
                     10000, fp))
        {
            column = 0;
            row++;
            char *value = strtok(buffer, ", ");

            while (value)
            {
                // Column 1
                if (column == 0)
                {
                    data[index].name = strdup(value);
                }

                // Column 2
                if (column == 1)
                {
                    data[index].no = atoi(value);
                }

                value = strtok(NULL, ", ");

                column++;
            }

            index++;
        }

        fclose(fp);
    }
}

void bubble_sort(struct record *arr)
{
    for (int x = 0; x < no_of_records; x++)
    {

        for (int y = 0; y < no_of_records - 1; y++)
        {

            if (arr[y].no > arr[y + 1].no)
            {

                struct record temp = arr[y];

                arr[y] = arr[y + 1];

                arr[y + 1] = temp;
            }
        }
    }
}
