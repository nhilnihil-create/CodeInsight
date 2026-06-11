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

int main()
{
    string s;
    cin>>s;
    int n = s.size();
    vvii alpha_idx(26);
    rep(i,26){
        alpha_idx[i].pb(0);
    }
    rep(i,n){
        alpha_idx[s[i] - 'a'].pb(i+1);
    }
    rep(i,26){
        alpha_idx[i].pb(n+1);
    }
    vii res(n + 2, infi);
    vector<set<ll>> bef(n + 2);
    res[n+1] = 0;
    repr(i,n,-1){
        rep(j,26){
            int idx = upper_bound(all(alpha_idx[j]), i) - alpha_idx[j].begin();
            int nex = alpha_idx[j][idx];
            if (res[nex]+1<res[i]){
                res[i]=res[nex]+1;
            }
        }
    }
    string t = "";
    int ans = res[0], now = 0;
    rep(i,ans){
        rep(j,26){
            int idx = upper_bound(all(alpha_idx[j]), now) - alpha_idx[j].begin();
            int nex = alpha_idx[j][idx];
            if (res[nex]+1==res[now]){
                t += (char)(j + 'a');
                now = nex;
                break;
            }
        }
    }
    cout << t << endl;
}
