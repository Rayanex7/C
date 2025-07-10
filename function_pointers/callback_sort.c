#include <stdio.h>

int ascending(int x, int y) {return x>y;}

int descending(int x, int y) {return x<y;}

int sort(int *intarray, int size, int (*fctpoint)(int, int))
{
    int i=0, q=0;
    int tmp=0;
    
    for (q=0;q<size-1;q++)
    {
        for (i=0;i<size-1;i++)
        {
            if (fctpoint(intarray[i], intarray[i+1]))
            {
                tmp = intarray[i];
                intarray[i] = intarray[i+1];
                intarray[i+1] = tmp; 
            }
        }
    }
}

int main()
{
    int size, sortType, i=0;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    printf("-----------------------------------------------------\n");

    int arr[size];

    for (i=0;i<size;i++)
    {
        printf("Element %d: \n", i+1);
        scanf("%d", &arr[i]);
    }

    printf("-----------------------------------------------------\n");

    printf("Choose type of sorting:\n1-Ascending\n2-Descending\n");
    scanf("%d", &sortType);
    if (sortType == 1) {sort(arr, size, ascending);}
    else {sort(arr, size, descending);}

    printf("-----------------------------------------------------\n");

    for (i=0;i<size;i++)
    {
        printf("%d\n", arr[i]);
    }

}