#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int g = 1;
    for (int i = min(a, b); i > 0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            g = i;
            break;
        }
    }
    if (c % g == 0)
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
}