#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if (b<a) {a=b; return 1;} return 0;}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cnt[a]++; cnt[b]++;
    }
    bool ans = true;
    rep(i, n) {
        if (cnt[i]%2 != 0) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}