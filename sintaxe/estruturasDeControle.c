#include <stdio.h>

int main(void)
{
    int num = 5;

    /*IF/ELSE IF*/
    if(num == 1)
    {
        printf("um\n");
    } else if(num == 2)
    {
        printf("dois\n");
    } else if(num == 3)
    {
        printf("três\n");
    } else if(num == 4)
    {
        printf("quatro\n");
    } else
    {
        printf("número maior que quatro\n");
    }

    /*SWITCH/CASE*/
    switch (num)
    {
    case 1:
        printf("um\n");
        break;
    case 2:
        printf("dois\n");
        break;
    case 3:
        printf("três\n");
        break;
    case 4:
        printf("quatro\n"); 
        break;
    default:
        printf("numero maior que quatro\n");
        break;
    }

    return 0;
}