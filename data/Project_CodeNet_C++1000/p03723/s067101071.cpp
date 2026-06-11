// https://atcoder.jp/contests/agc014/tasks/agc014_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);

    if ((a == b) & (b == c))
    {
        cout << (a & 1 ? 0 : -1) << endl;
        return 0;
    }

    int ans = 0;
    while (((a | b | c) & 1) == 0)
    {
        long na, nb, nc;
        na = (b + c) / 2;
        nb = (c + a) / 2;
        nc = (a + b) / 2;
        a = na;
        b = nb;
        c = nc;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
