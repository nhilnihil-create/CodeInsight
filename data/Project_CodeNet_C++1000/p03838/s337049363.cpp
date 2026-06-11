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
    ll ans;
    if (x > y)
    {
        if (x < 0)
        {
            ans = 2 + abs(y) - abs(x);
        }
        else if (y > 0)
        {
            ans = 2 + abs(x) - abs(y);
        }
        else
        {
            ans = 1 + max(abs(x) - abs(y), abs(y) - abs(x));
        }
    }
    else if (y > x)
    {
        if (y <= 0)
        {
            ans = abs(x) - abs(y);
        }
        else if (x >= 0)
        {
            ans = abs(y) - abs(x);
        }
        else 
        {
            ans = 1 + max(abs(x) - abs(y), abs(y) - abs(x));
        }
    }
    else
    {
        ans = 0;
    }
    
    cout << ans << endl;
}
