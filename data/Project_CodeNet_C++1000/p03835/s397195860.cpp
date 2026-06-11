#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define scl(n) scanf("%lld", &n)
#define pcl(n) printf("%lld\n", n)
#define pcl1(n) printf("%lld ", n)
#define nln printf("\n")
#define dev(x) cout << #x << " " << x << " ";
#define PTT pair<ll, ll>

map<ll, ll> mp, mp1;
map<ll, ll>::iterator itr;

int main()
{
    ll t, n, x, k, s;
    scl(k);
    scl(s);
    ll cnt = 0;
    for (int i = 0; i <= k; i++)
    {
        n = s - i;
        for (int j = 0; j <= k; j++)
        {
            if (n >= j)
            {
                if (n - j <= k)
                {
                    cnt++;
                }
            }
        }
    }
    pcl(cnt);
    return 0;
}