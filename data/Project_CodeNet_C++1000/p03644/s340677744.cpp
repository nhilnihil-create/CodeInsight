#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {64,32,16,8,4,2,1};
    int n;
    cin >> n;

    for(int i=0; i<7; i++)
    {
        if(a[i] <= n)
        {
            cout << a[i];
            break;
        }
    }
    return 0;
}