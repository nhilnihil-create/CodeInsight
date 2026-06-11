#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[3];
    int a = 0, b = 0;

    for (int i = 0; i < 3; ++i)
    {
        cin >> num[i];
        if (num[i] == 5)
            a++;
        else if (num[i] == 7)
            b++;
    }
    if (a == 2 && b == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}