#include <bits/stdc++.h>
#define ll long long
#define Nmax 205
using namespace std;

ll n, x;

ll solve(ll a, ll b){
    if (a > b) swap(a,b);
    ll ans = 0;
    ans = ((b / a - 1) * 2 + 1) * a;
    ll c = b % a;
    if (c == 0) return ans;
    return ans + a + solve(c, a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x;
    cout << n + solve(x,n-x);
    return 0;
}
