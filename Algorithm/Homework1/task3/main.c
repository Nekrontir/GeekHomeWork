#include <stdio.h>
#include <stdlib.h>

int ToBin( int n ) // функция перевода числа в двоичное
{
   if ( n >= 2 )
    {
      ToBin( n/2 );
    }
   printf(" %d" , n % 2);
   return;
}

int degree(int x, int y) // рекурсивное возведение в степень
{
    return y == 0 ? 1 : x * degree(x, y-1);
}

int degree2(int x, int y) // функция возведения числа в степень с использованием чётности степени
{
    if (y % 2 == 0)
        return y == 0 ? 1 : degree(x*x, y/2);
    else
        return y == 0 ? 1 : x * degree(x, y-1);
}

int routes(int a, int b) //функция поиска путей короля без припятствий
{
    if (a == 0 && b == 0)
        return 0;
    else if (a == 0 ^ b == 0)
        return 1;
    else
        return routes(a, b-1) + routes(a-1, b);
}


int main()
{
    // Задание 1
    int n;
    printf("Enter a number for convert to binary system\n");
    scanf("%d",&n);
    printf("Number in binary system is ");
    ToBin(n);
    printf("\n");
    //задание 2
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
    //задание с королём , не осилил. но как я понял нужно взять статический массив и всё сделать в нём.
    const int sizeA = 5;
    const int sizeB = 5;
    for (int b = 0; b < sizeB; ++b)
    {
        for(int a = 0; a < sizeA; ++a)
        {
            printf("%5d", routes(a,b));
        }
        printf("\n");
    }
    return 0;
}
