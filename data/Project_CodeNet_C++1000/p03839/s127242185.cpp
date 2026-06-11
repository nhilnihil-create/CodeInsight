#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

int main()
{
    ll n,k;
    cin >> n >> k;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll s(n+1,0);
    vll s2(n + 1, 0);
    rep(i,n){
        s2[i + 1] = s2[i] + a[i];
        s[i + 1] = s[i] + max(0ll,a[i]);
    }
    ll ans = 0;
    repf(i,k,n+1){
        ans=max(ans,max(s[n]-(s[i]-s[i-k]),s[n]-(s[i]-s[i-k])+s2[i]-s2[i-k]));
    }
    cout << ans << endl;
}