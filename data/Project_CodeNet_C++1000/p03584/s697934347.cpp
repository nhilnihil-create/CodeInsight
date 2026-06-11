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

using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)

#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll mod = 1e9 + 7;
const int infi = 2147483647;
const ll infl = 1e17;

int main()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> data;
    ll S = 0;
    rep(i,n){
        ll a, b;
        cin>>a>>b;
        if (a>k)
            continue;
        else{
            S += b;
            repr(j,30,-1){
                if (!((a>>j)&1))
                    continue;
                if ((k>>j)&1){
                    data[j] += b;
                }
                else {
                    data[j]+=b;
                    break;
                }
            }
        }
    }
    ll ans = 0;
    repr(i,30,-1){
        if((k>>i)&1){
            ans = max(S - data[i], ans);
        }
        else
            S -= data[i];
    }
    ans = max(S, ans);
    cout << ans << endl;
}
