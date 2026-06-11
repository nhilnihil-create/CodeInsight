#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int W, a, b;
    cin >> W >> a >> b;
    int array[2][2] = {{a, a + W}, {b, b + W}};

    if (array[1][0] - array[0][1] > 0 || array[0][0] - array[1][1] > 0)
    {
        if (a < b)
        {
            cout << array[1][0] - array[0][1];
        }

        if (b < a)
        {
            cout << array[0][0] - array[1][1];
        }
    }

    else
        cout << 0;
}