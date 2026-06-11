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
#define pb(x) push_back(x)
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

int n,m;
vii edges[100005];

int main()
{
    cin >> n >> m;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    bool used[n] = {};
    int now = 0;
    vii left = {0};
    used[0] = true;
    bool flag = true;
    while (flag){
        flag = false;
        for (auto nex:edges[now]){
            if (used[nex])
                continue;
            now = nex;
            used[now] = true;
            left.pb(now);
            flag = true;
            break;
        }
    }
    vii right = {0};
    now = 0;
    flag = true;
    while(flag){
        flag = false;
        for (auto nex:edges[now]){
            if (used[nex])
                continue;
            now = nex;
            used[now] = true;
            right.pb(now);
            flag = true;
            break;
        }
    }
    cout << right.size() + left.size() - 1 << endl;
    repr(i, right.size() - 1, -1) cout << 1+right[i] << " ";
    repf(i, 1, left.size()) cout << 1+left[i] << " ";
    cout << endl;
}
