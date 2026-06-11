#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while(ans < 1e6)
    {
        if(a % 2 || b % 2 || c % 2)
        {
            cout << ans << endl;
            return 0;
        }
        ans++;
        int na = (b+c) / 2;
        int nb = (a+c) / 2;
        int nc = (a+b) / 2;
        a = na;
        b = nb;
        c = nc;
    }
    cout << -1 << endl;
}


