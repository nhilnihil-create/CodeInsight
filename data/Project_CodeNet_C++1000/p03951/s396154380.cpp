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
    string s, t;
    cin >> n >> s >> t;
    
    // 何文字ずらすか
    rep(i, n) {
        // 重なっている部分のチェック
        bool flag = true;
        rep(j, n-i) {
            if (s[i+j] != t[j]) flag = false;
        }
        if (flag) {
            cout << n+i << endl;
            return 0;
        }
    }
    cout << 2*n << endl;
}