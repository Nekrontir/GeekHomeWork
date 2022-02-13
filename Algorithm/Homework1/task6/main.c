#include <stdio.h>
#include <stdlib.h>
#define SZ 10

#define T int
#define SIZE 1000
#define true 1==1
#define false 1!=1
/*
typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean push(T data)
{
    if (cursor < SIZE)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
        printf("%s \n","Stack overflow");
        return false;
    }
}

T pop()
{
    if(cursor !=1 )
    {
        return Stack[cursor--];
    }
    else
    {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}
*/

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

/*
void toBin (int x)
{
    int n;
    while(x!=0)
    {
        x=x/2;
        n=x%2;
        push(n);
    }
}

void bin()
{
      while (cursor!=-1)
    {
        printf("%d", pop());
    }
    printf("\n");
}
*/

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
/*
    toBin(5);
    bin();
*/

    return 0;
}
