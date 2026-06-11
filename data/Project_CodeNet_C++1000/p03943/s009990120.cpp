#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int a,b,c; cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum & 1) { puts("No"); return 0; }

    int half = sum / 2;
    if ((a == half) || (b == half) || (c == half))
        puts("Yes");
    else
        puts("No");

    return 0;
}
