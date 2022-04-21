#include <stdio.h>

int main(void)
{
    /*FOR*/ 
    int i;   
    for(i=0; i<=10; i++)
    {
        printf("%d\n",i);
    }

    printf("\n\n");

    /*WHILE*/
    int j = 0;
    while(j<=10)
    {
        printf("%d\n", j);
        j++;
    }

    printf("\n\n");

    /*DO WHILE*/
    int k = 0;
    do
    {
        printf("%d\n", k);
        k++;
    }
    while (k<=10);
    
    return 0;
}