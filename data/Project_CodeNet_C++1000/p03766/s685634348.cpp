#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long ll;


const int MAXN = 1000005;
const int MOD = 1000000007;
ll s[MAXN];
int main()
{
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    s[0] = 1;
    s[1] = 1;
    ll S = 0;
    for (int i = 2; i <= n; i++)
    {
        s[i] = (s[i-1] + S) % MOD;
        S = (S + s[i-2]) % MOD;
    }

    ll g = 0;
    for (int i = 0; i <= n-2; i++)
    {
        g += s[i] * (i+1);
        g %= MOD;
    }

  //  cout << g << endl;
   // cout << s[n-1] <<  endl;

    ll ans = (  g + s[n] + ((s[n-1]*(n-1))%MOD) + (S*((n-1)*(n-1)%MOD)%MOD)  ) % MOD;
    cout << ans;
    return 0;
}

