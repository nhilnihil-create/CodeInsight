#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " = " << x << endl
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;


const int MAXN = 100005;
ll a[MAXN];
ll b[MAXN];

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }

    ll pow = 1;
    for (int i = 1; i < 34; i++) pow *= 2;


    ll ans = 0;
    while (pow)
    {
        pow /= 2;
        if (!(k & pow)) continue;
        ll mask = (k - pow) | (pow-1);
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask | a[i]) == mask)
            {
                res += b[i];
            }
        }
        ans = max(ans, res);
        ///cout << pow << " " << mask << " " << ans << endl;
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        if ((k | a[i]) == k)
            res += b[i];
    }
    ans = max(ans, res);
    cout << ans;
    return 0;
}

