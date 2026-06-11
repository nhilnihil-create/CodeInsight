#pragma 03
#pragma GCC target("avx")
#pragma GCC optimization ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int long long
#define eb emplace_back
#define ef emplace_front
#define rep(i, x, n) for (int i = x; i < n; ++i)
#define mp make_pair
#define fi first
#define se second
#define ii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vii vector<pair<int, int>>
#define reverse(s) reverse(s.begin(), s.end())
#define ld long double
#define vs vector<string>
#define inf INT_MAX
#define vc vector<char>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vb vector<bool>
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define ub(a, x) upper_bound(a.begin(), a.end(), x) 
#define vvi vector<vi>
#define mine(a) min_element(a.begin(),a.end())
#define maxe(a) max_element(a.begin(), a.end())
#define iota(a,i) iota(a.begin(),a.end(),i)
#define fileopen(filename) if (fopen(filename".INP", "r")) {freopen(filename".INP", "r", stdin);freopen(filename".OUT", "w", stdout);}
bool cmp(ii x, ii y) {
    if (x.first != y.first) return x.first > y.first;
    return x.second < y.second;
}
signed main() {
    fileopen("");
    fastio;
    int n;
    cin >> n;
    vii a(n + 1);
    vi ans(n + 1, 0);
    rep(i, 1, n + 1) {
        cin >> a[i].first;
        a[i].second = i;
    }
    a[0] = mp(inf, 0);
    sort(a.begin(), a.end(), cmp);
    /*for (ii i : a) cout << i.first << " " << i.second << endl;*/
    int sum = a[1].first, cnt = 1;
    ii pos = a[1];
    rep(i, 2, n + 1) {
        if (a[i].first < pos.first) {
            ans[pos.second] += sum - a[i].first * cnt;
            ++cnt;
            sum = a[i].first * cnt;
            if (a[i].second < pos.second) pos = a[i];
            else pos.first = a[i].first;
        }
        else {
            ++cnt;
            sum += a[i].first;
        }
    }
    ans[pos.second] += sum;
    rep(i, 1, n + 1) cout << ans[i] << endl;
}