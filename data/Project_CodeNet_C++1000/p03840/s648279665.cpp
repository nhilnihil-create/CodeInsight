#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a[7], S=0;
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }
    S = a[1];
    if (a[0] % 2 + a[3] % 2 + a[4] % 2 >= 2 && a[0] > 0 && a[3] > 0 && a[4] > 0)
    {
        S += 3;
        a[0]--;
        a[3]--;
        a[4]--;
    }
    S += (a[0]/2)*2;
    S += (a[3]/2)*2;
    S += (a[4]/2)*2;
    a[0] %= 2;
    a[3] %= 2;
    a[4] %= 2;
    cout << S;
    return 0;
}
