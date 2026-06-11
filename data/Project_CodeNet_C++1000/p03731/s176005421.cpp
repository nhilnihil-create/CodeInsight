#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100

int main()
{
    ll n, t;
    cin >> n >> t;
    ll ans = 0, tprev = 0, tcurr = 0;
    for(int i = 0; i < n; i++)
    {
        ll tt;
        cin >> tt;
        if(i == 0)
        {
            tcurr = tt;
        }
        else
        {
            tprev = tcurr;
            tcurr = tt;
        }

        ans += min(tcurr - tprev, t);

    }
    ans += t;

    cout << ans << endl;
}