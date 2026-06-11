#define MOD 109+7
#define  endll  "\n"
#define  ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

#include <bits/stdc++.h>

using namespace std;
const int N = 2e5, M = 2 * N, SEGN = 2 << (32 - __builtin_clz(N));

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input", "rt", stdin);
    // freopen("output", "wt", stdout);
#endif
    int x, y;
    cin >> x >> y;
    cout << (x + y) % 24;
}