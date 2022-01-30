#include <stdio.h>
#include <stdlib.h>

int ToBin( int n )
{
   if ( n >= 2 )
    {
      ToBin( n/2 );
    }
   printf(" %d" , n % 2);
   return;
}

int degree(int x, int y)
{
    return y == 0 ? 1 : x * degree(x, y-1);
}

int degree2(int x, int y)
{
    if (y % 2 == 0)
        return y == 0 ? 1 : degree(x*x, y/2);
    else
        return y == 0 ? 1 : x * degree(x, y-1);
}


int main()
{
    int n;
    printf("Enter a number for convert to binary system\n");
    scanf("%d",&n);
    printf("Number in binary system is ");
    ToBin(n);
    printf("\n");
    int x;
    int y;
    printf("Enter a number for calculate  \n");
    scanf("%d",&x);
    printf("Enter a degree of number \n");
    scanf("%d",&y);
    printf("Using fist option ");
    printf("%d \n", degree(x,y));
    printf("Using second option ");
    printf("%d \n", degree2(x,y));
    return 0;
}
