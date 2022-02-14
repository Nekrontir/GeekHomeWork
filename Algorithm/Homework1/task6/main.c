#include <stdio.h>
#include <stdlib.h>
#define SZ 10
#define Stack 100

int array[Stack];
int i = -1;

void push(int x)
{
        i++;
        array[i]=x;

}

void pop()
{
    while( i != -1)
    {
        printf(" %d", array[i]);
        i--;
    }

}

void toBin(int n) //функция перевода в двоичную систему
{
    do
    {
        push(n%2);
        n = n/2;

    }
    while(n!=0);
    pop();
    printf("\n");
}

typedef struct
{
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;


void init()
{
    for(int i=0; i<SZ; i++)
    {
        arr[i]=0;
    }
    head=0;
    tail=0;
    items=0;
}

void ins( int pr, int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if(items == 0)
    {
        arr[tail++] = node;
        items++;
    }
    else if (items==SZ)
    {
        printf("%s \n", " Queue is full");
        return;
    }
    else
    {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for(i=head;i<tail; ++i)
        {
            idx= i%SZ;
            if (arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx%SZ;
        i++;
        while (i<=tail)
        {
            idx= i%SZ;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag]=node;
        items++;
        tail++;
    }
}

Node* rem()
{
    if(items==0)
        {
            return NULL;
        }
    else
    {
        int idx = head++ % SZ;
        Node *tmp =arr[idx];
        arr[idx] = NULL;
        items--;
        return tmp;
    }
}

void printQueue()
{
    printf("[ ");
    for (int i = 0; i < SZ; ++i)
    {
        if (arr[i] == NULL)
            printf("[*,*]");
    else
        printf("[%d, %d]", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}



int main()
{
    // задание по приоритетной очереди
    init();
    ins(1,11);
    ins(3,22);
    ins(4,33);
    ins(2,44);
    ins(3,55);
    ins(4,66);
    ins(5,77);
    ins(6,88);
    ins(7,99);
    printQueue();
    for (int i=0; i<6 ; ++i)
    {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr,n->dat);
    }
    printQueue();

    ins(2,44);
    ins(4,44);
    printQueue();

    //задание по переводу числа из десятичной в двоичную
    push(5); //проверка работы стека
    push(6); //проверка работы стека
    pop();   //проверка работы стека
    printf("\n");
    printf("\n");
    toBin(5);
    toBin(30);
    toBin(89);
    toBin(1);


    return 0;
}
