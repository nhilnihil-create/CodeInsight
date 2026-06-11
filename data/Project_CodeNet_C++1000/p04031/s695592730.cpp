#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ep emplace_back
#define st first
#define sc second

using namespace std;

const ll mod = 998244353;
const int e = 1e6 + 69;
const int base = 311;

// dung igt thay cho gt luc tinh giai thua
// 3
// cach tao hoan vi tu n so : n*(n+1)/2;

ll a[e];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    ll minn = 1e18;
    for(ll x=-100; x<=100; x++)
    {
        ll ans = 0;
        for(int j=1; j<=n; j++)
        {
            ans += (a[j] - x) * (a[j] - x);
        }
        minn = min(ans, minn);
    }
    cout << minn;
}
