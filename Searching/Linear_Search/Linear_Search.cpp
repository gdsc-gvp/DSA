#include <bits/stdc++.h> //header file that includes every standard library.
using namespace std;
#define int long long

int32_t main()
{

    int n; //number of elements
    cin >> n;
    int a[n]; //array of size n
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<"Enter an number to be searched!\n";
    int search_element; //element to be searched
    cin >> search_element;

    int position = -1; //a variable to store the position of the element to be searched
    for (int i = 0; i < n; i++)
    {
        if (a[i] == search_element)
        {
            position = i;
            break;
        }
    }
    if (position == -1)
        cout << "Element is not Found\n";
    else

        cout << "Element Found at position " << position + 1 << '\n';
}

// Talking about its time complexity
//Best Case - O(1)
//Average Case - O(n/2)
//Worst Case - O(n)