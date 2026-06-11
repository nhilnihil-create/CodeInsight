#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
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
    string s;
    cin >> s;
    vi ans(n, -1);
    const int sheep = 0;
    const int wolf = 1;
    rep(t, 4) {
        bool flag1 = false;
        bool flag2 = false;
        if (t == 0) {
            ans[0] = sheep;
            ans[1] = sheep;
            for (int i = 2; i < n; ++i) {
                if (s[i-1] == 'o') {
                    if (ans[i-1] == sheep) {
                        ans[i] = ans[i-2];
                    } else {
                        ans[i] = 1 - ans[i-2];
                    }
                } else {
                    if (ans[i-1] == sheep) {
                        ans[i] = 1 - ans[i-2];
                    } else {
                        ans[i] = ans[i-2];
                    }
                }
            }
            if (s[0] == 'o') {
                if (ans[n-1] == sheep) flag1 = true;
            } else {
                if (ans[n-1] == wolf) flag1 = true;
            }
        }
        if (t == 1) {
            ans[0] = sheep;
            ans[1] = wolf;
            for (int i = 2; i < n; ++i) {
                if (s[i-1] == 'o') {
                    if (ans[i-1] == sheep) {
                        ans[i] = ans[i-2];
                    } else {
                        ans[i] = 1 - ans[i-2];
                    }
                } else {
                    if (ans[i-1] == sheep) {
                        ans[i] = 1 - ans[i-2];
                    } else {
                        ans[i] = ans[i-2];
                    }
                }
            }
            if (s[0] == 'o') {
                if (ans[n-1] == wolf) flag1 = true;
            } else {
                if (ans[n-1] == sheep) flag1 = true;
            }   
        }
        if (t == 2) {
            ans[0] = wolf;
            ans[1] = sheep;
            for (int i = 2; i < n; ++i) {
                if (s[i-1] == 'o') {
                    if (ans[i-1] == sheep) {
                        ans[i] = ans[i-2];
                    } else {
                        ans[i] = 1 - ans[i-2];
                    }
                } else {
                    if (ans[i-1] == sheep) {
                        ans[i] = 1 - ans[i-2];
                    } else {
                        ans[i] = ans[i-2];
                    }
                }
            }
            if (s[0] == 'o') {
                if (ans[n-1] == wolf) flag1 = true;
            } else {
                if (ans[n-1] == sheep) flag1 = true;
            }   
        }
        if (t == 3) {
            ans[0] = wolf;
            ans[1] = wolf;
            for (int i = 2; i < n; ++i) {
                if (s[i-1] == 'o') {
                    if (ans[i-1] == sheep) {
                        ans[i] = ans[i-2];
                    } else {
                        ans[i] = 1 - ans[i-2];
                    }
                } else {
                    if (ans[i-1] == sheep) {
                        ans[i] = 1 - ans[i-2];
                    } else {
                        ans[i] = ans[i-2];
                    }
                }
            }
            if (s[0] == 'o') {
                if (ans[n-1] == sheep) flag1 = true;
            } else {
                if (ans[n-1] == wolf) flag1 = true;
            }   
        }
        if (s[n-1] == 'o') {
            if (ans[n-1] == sheep && ans[n-2] == ans[0]) flag2 = true;
            if (ans[n-1] == wolf && ans[n-2] != ans[0]) flag2 = true;
        } else {
            if (ans[n-1] == sheep && ans[n-2] != ans[0]) flag2 = true;
            if (ans[n-1] == wolf && ans[n-2] == ans[0]) flag2 = true;
        }
        if (flag1 && flag2) {
            rep(i, n) {
                cout << (ans[i] == sheep ? 'S' : 'W');
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}