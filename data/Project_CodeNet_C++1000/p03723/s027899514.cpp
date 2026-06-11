#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int counter = 0;
    if (a == b && a == c && b == c)
    {
        if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0)
        {
            cout << "0";
            return 0;
        }
        else
        {
            cout << "-1";
            return 0;
        }
    }
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
    {
        int tempa = a;
        int tempc = c;
        int tempa2 = a;
        int tempb2 = b;
        a = (b / 2) + (c / 2);
        b = (tempa / 2) + (tempc / 2);
        c = (tempa2 / 2) + (tempb2 / 2);
        counter++;
    }
    cout << counter;
}