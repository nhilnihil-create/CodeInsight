#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int judge(int a, int b, int c)
{
    if (a == b && b == c && a % 2 == 0)
        return -1;
    else if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int64_t a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (judge(a, b, c) == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    while (judge(a, b, c) == 1)
    {
        int64_t s, t, u;
        s = a;
        t = b;
        u = c;
        a = (t + u) / 2;
        b = (s + u) / 2;
        c = (s + t) / 2;
        ans++;
    }
    cout << ans << endl;
}