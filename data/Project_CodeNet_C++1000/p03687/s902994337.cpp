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
    
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1000;
    for (char c = 'a'; c <= 'z'; c++) {
        int cnt = 0;
        int now = 0;
        bool flag = false;
        rep(i, n) {
            if (s[i] == c) {
                flag = true;
                chmax(now, cnt);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        chmax(now, cnt);
        if (flag) chmin(ans, now);
    }
    cout << ans << endl;
}