#include <bits/stdc++.h>
using namespace std;

int nr[100010];
int n;

int cmmdc(int a, int b)
{
    while (a) {
        b %= a;
        a ^= b ^= a ^= b;
    }
    return b;
}

bool castiga()
{
    int x(0), y(0), py;
    bool unu(0);
    for (int i(0); i < n; i++) {
        if (nr[i] & 1)
            y++, py = i;
        else
            x++;
        if (nr[i] == 1)
            unu = 1;
    }

    if (unu) { /// gcd won't ever be != 1, so parity counts
        int stotal(0);
        for (int i(0); i < n; i++)
            stotal ^= nr[i] - 1;
        return (stotal & 1);
    }

    if (x == 0) /// have to make even, oponent makes it odd again
        return false;
    if (x % 2 == 1) /// makes it odd, upper case
        return true;
    if (x % 2 == 0 && y > 1) /// if i change one of the evens, the oponent changes another
        return false;
    /// i am here so y == 1

    nr[py]--;

    x = 0;
    for (int i(0); i < n; i++)
        x = cmmdc(x, nr[i]);
    for (int i(0); i < n; i++)
        nr[i] /= x;
    return !castiga();
}

int main()
{
    cin >> n;
    for (int i(0); i < n; i++)
        cin >> nr[i];

    cout << (castiga() ? "First" : "Second");
    return 0;
}
