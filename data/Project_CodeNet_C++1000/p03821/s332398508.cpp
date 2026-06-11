#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll cnt = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    rep(i, n) {
        cnt += ((a[i]+cnt+b[i]-1)/b[i])*b[i] - (a[i]+cnt);
    }
    cout << cnt << endl;
}