#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter a number \n");
    scanf("%d" , &number);
    printf("\n");
    int d=0, i=1;
    while (i<= number)
    {
        if(number % i++ == 0)
            d++;
        else
            continue;
        if (d == 3)
            break;
    }
    printf("Namber %d is %s simple\n", number , (d==2)? "" : "not" );
    return 0;
}
