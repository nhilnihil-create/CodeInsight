#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main()
{
    ll x, y;
    cin >> x >> y;

    ll ans = 0;
    if (x <= y)
    {
        if (x * y >= 0)
        {
            ans = y - x;
        }
        else
        {
            ans = abs(abs(x) - abs(y)) + 1;   
        }
    }
    else
    {
        if (x * y > 0)
        {
            ans = abs(abs(x) - abs(y)) + 2;   
        }
        else
        {
            ans = abs(abs(x) - abs(y)) + 1;   
        }
    }

    cout << ans << endl;
}
