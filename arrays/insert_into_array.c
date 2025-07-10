#include <stdio.h>
#include <math.h>


//Insert at any position
int main()
{
	int size, i=0, val, pos;

	printf("Enter the size of Array: ");
    scanf("%d", &size);
	
	int arr[size];

	for (i=0;i<size;i++)	//Taking values of array from user
    {
        printf("Element %d: \n", i+1);
        scanf("%d", &arr[i]);
    }

	printf("-----------------------------------------------------\n");
	for (i=0;i<size;i++) {printf("%d\n", arr[i]);}	//printing elements of array so user know the position where to insert
	printf("-----------------------------------------------------\n");

	printf("Element to insert: \n");
	scanf("%d", &val);

	printf("In which position?\n");
	scanf("%d", &pos);

	for(i=size-1;i>=pos-1;i--) {arr[i+1] = arr[i];}		//logic to insert element
	arr[pos-1] = val;

	printf("-----------------------------------------------------\n");		//printing array elements
	for (i=0;i<=size;i++) {printf("%d\n", arr[i]);}
	return 0;
}

/* Insert After all elements
void main()
{
	int arr[40]={1,2,3,4,5};			
	int i;
	int size=(sizeof(arr)/sizeof(arr[0]));
	int new_val = 6;

	for(i=0;i<size;i++)
	{
		if(arr[i] == 0)
		{
			arr[i] = new_val;
			break;
		}
	}
	for(i=0;i<6;i++)
	{
		printf("%d\n", arr[i]);
	}
}
*/




