


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
const ll infl = 1e17;


int main()
{
    ll n;
    cin >> n;
    ll s = 0;
    vll a(n);
    rep(i, n){ cin >> a[i];
        s += a[i];
    }
    ll bunbo = (n + 1) * n / 2;
    if (s%bunbo!=0){
        cout << "NO" << endl;
        return 0;
    }
    ll xs = s / bunbo;
    vll x(n);
    if ((xs+a[n-1]-a[0]<0) || ((xs+a[n-1]-a[0])%n!=0)){

        cout << "NO" << endl;
        return 0;
    }
    else
        x[0] = (xs + a[n - 1] - a[0]) / n;
    rep(i,n-1){

        if ((xs + a[i] - a[i+1] < 0) || ((xs + a[i] - a[i+1]) % n != 0))
        {

            cout << "NO" << endl;
            return 0;
        }
        else
            x[0] = (xs + a[i] - a[i+1]) / n;
    }
    cout << "YES" << endl;
}