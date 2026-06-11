#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

ll fact(int n)
{
    ll ans = 1;
    for(int i = 2; i <= n; i++)
    {
        ans = (ans*i)%1000000007;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    if(abs(n-m) > 1)
    {
        cout << 0 << endl;
        return 0;
    }

    if(abs(n-m) == 1)
    {
        ll ans = (fact(n)*fact(m))%1000000007;
        cout << ans << endl;
        return 0;
    }
    else
    {
        ll ans = (2*fact(n)*fact(m))%1000000007;
        cout << ans << endl;
        return 0;
    }
}
