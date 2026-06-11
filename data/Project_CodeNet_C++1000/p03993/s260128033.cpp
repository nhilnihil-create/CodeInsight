#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> nakayoshi(n);
    rep(i, n) nakayoshi[i] = a[i];
    int ans = 0;
    rep(i, n) {
        if (nakayoshi[a[i]] == i) ans++;
    }
    ans /= 2;
    cout << ans << endl;
}