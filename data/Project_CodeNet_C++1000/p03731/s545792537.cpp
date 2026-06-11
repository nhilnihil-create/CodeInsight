/**
*    created: 27.06.2020 18:43:33
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, time;
    cin >> n >> time;
    int sum = 0;
    vector<int> t(n);
    rep(i,n) cin >> t[i];
    rep2(i,1,n) sum += min(time,t[i]-t[i-1]);
    sum += time;
    cout << sum << endl;
    return 0;
}