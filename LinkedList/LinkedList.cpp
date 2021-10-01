#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    struct node
    {
        int t;
        struct node *next;
    };
    typedef struct node NODE;
    NODE *first, *start, *temp;
    bool choice = 1;
    bool f = 1;
    int count = 0;
    while (choice)
    {
        start = (NODE *)malloc(sizeof(NODE));
        if (f)
        {
            first = start;
            temp = start;
            f = 0;
        }
        else
        {
            temp->next = start;
            temp = start;
        }

        cout << "Enter the number " << endl;
        cin >> start->t;
        cout << "Enter your choice(1 or 0)" << endl;
        cin >> choice;
        if (choice == 0)
        {
            temp->next = NULL;
        }
    }
    while (first != NULL)
    {
        cout << first->t << endl;
        first = first->next;
    }
}
