#include <stdio.h>

void Triangle()
{
    int i,j;

    for(i=0;i<10;i++)
    {
        for (j=0;j<i+1;j++)
        {
            printf("*");
        }
    printf("\n");
    }
}

void right_triangle()
{
    int i,j,k,l;

    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            if(j != 6/2)
            {
                for(l=0;l<j/2;l++)
                {
                    printf(" ");
                }
                for(k=j/2;k<j;k++)
                {
                    printf("*");
                }
                printf("\n");
            }
            
        }
    }
}

void Rectangle()
{
    int i,j,k;
    int l,s;

    printf("lenght:\n");
    scanf("%d", &l);

    printf("Width:\n");
    scanf("%d", &s);

    for(i=1;i<=l;i++)
    {
        if (i == 1 || i == l)
        {
            for(j=1;j<=s;j++)
            {
                printf("*");
            }
            printf("\n");
        }
        if (i != 1 && i != l)
            {
                printf("*");
                for (k=1;k<s-1;k++)
                {
                    printf(" ");
                }
                printf("*");
                printf("\n");
            }
            }

}

void main()
{
    Triangle();
    Rectangle();
    //right_triangle(); //i have a problem, i'll fix it later
}