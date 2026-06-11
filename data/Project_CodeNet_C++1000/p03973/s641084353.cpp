#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    int a;
    cin >> a;

    int now = 2;
    ll cnt = a - 1;
    rep(i, 0, n - 1)
    {
        cin >> a;

        if (a < now)
            continue;
        else if (a == now)
            ++now;
        else if (a % now == 0)
            cnt += (ll) (a - 1) / now;
        else
            cnt += (ll) a / now;
    }

    cout << cnt << endl;
    return 0;
}
