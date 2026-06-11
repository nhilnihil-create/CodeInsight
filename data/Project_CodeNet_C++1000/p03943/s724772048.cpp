#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < 2; i++)
    {
        if (a > b)
        {
            swap(a, b);
        }
        if (b > c)
        {
            swap(b, c);
        }
    }
    if (a + b == c)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}