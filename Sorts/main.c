#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
struct bool
{
    unsigned char bool:1;
};

int Split(int* vector, int head, int tail)
{
    int i = head + 1, j = tail, aux = 0;

    while(i <= j)
    {
        if(vector[i] < vector[head]) i++;
        else
        {
            if(vector[j] > vector[head]) j--;
            else
            {
                int aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
                i++;
                j--;
            }
        }
    }

    aux = vector[head];
    vector[head] = vector[j];
    vector[j] = aux;

    return j;
}

void QuickSort(int* vector, int head, int tail)
{
    if(head < tail)
    {
       int half = Split(vector, head, tail);
       QuickSort(vector, head, half - 1);
       QuickSort(vector, half + 1, tail);
    }
}

int main()
{
    int *vector = malloc(sizeof(int));

    vector[0] = 4;
    vector[1] = 1;
    vector[2] = 9;
    vector[3] = 50;
    vector[4] = 0;
    vector[5] = 7;

    QuickSort(vector, 0, 5);

    for(int i = 0; i < 6; i++)
    {
        printf("%d, \n", vector[i]);
    }

    return 0;
}
