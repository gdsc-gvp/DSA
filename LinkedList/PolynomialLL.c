#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void Create()
{
    struct Node *t, *last;
    int num;
    printf("Enter number of terms\n");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp\n");

    for (int i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p,int x)
{
    long val=0;

    while (p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
    
}

int main()
{
    Create();
    Display(poly);
    printf("%ld\n",Eval(poly,1));
    return 0;
}