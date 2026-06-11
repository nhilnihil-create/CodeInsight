/*
    Problem 14
    https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = LINF;
    // 一番前は絶対見えるので
    // 2番目以降からK - 1個選んで見えるようにする
    for (int b = 0; b < (1 << (n - 1)); b++) {
        if (__builtin_popcount(b) != k - 1) continue;
        ll maxH = a[0], sum = 0;
        for (int i = 1; i < n; i++) {
            if ((b >> (i - 1)) & 1) {
                if (maxH >= a[i]) {  // 低ければmaxH+1まで増築
                    maxH += 1;
                    sum += maxH - a[i];
                }
            }
            maxH = max(a[i], maxH);  // 高さの更新
        }
        ans = min(sum, ans);
    }
    cout << ans << '\n';
}