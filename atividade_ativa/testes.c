#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;
    char num[20];
    printf("Digite um número de 1 a 5\n");
    scanf("%s", num);

    number = atoi(num);



    printf("'%s'\n", num);
    printf("%d\n", number);


    return 0;
}