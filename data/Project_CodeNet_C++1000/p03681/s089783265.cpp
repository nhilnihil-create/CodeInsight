#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
int factorial(int n)
{
    ll ans = 1;
    for (ll i = 1; i <=n; i++)
    {
        ans *= i;
        ans %= MOD;
    }
    ans %= MOD;
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;
    ll ans;
    // 常にn>m
    if(n<m)
    {
        swap(n,m);
    }
    if(n-m>=2)
    {
        cout << 0 << endl;
        return 0;
    }
    if(n==m)
    {
        ll temp = factorial(n);
        ans = (2*temp*temp)%MOD;
    }
    if(n>m)
    {
        ll temp = factorial(m);
        ll temp2 = factorial(m)*(ll)n%MOD;
        ans = temp*temp2%MOD;
    }
    cout << ans << endl;
    return 0;
}