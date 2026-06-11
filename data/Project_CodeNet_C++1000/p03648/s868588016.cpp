#include<bits/stdc++.h>
using namespace std;
//type
typedef long long ll;
using pii = pair<int, int>;
//constant
#define inf (int)(1e9+7)
#define mod (ll)(1e9+7)
#define eps 1e-10
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {1, -1, 0, 0, -1, 1, 1, -1};
//manip
template<class T> bool chmax(T &a, T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, T &b) {if (a > b) {a = b; return 1;} return 0;}
#define UNIQUE(v) v.erase(unique(v.begin(), v.end(), v.end());
#define fill(x, y) memset(x, y, sizeof(x))
#define ceil(a, b) a / b + !!(a % b)
template<class T> T power(T a, T b)
{return b ? power(a * a % inf, b / 2) * (b % 2 ? a : 1) % inf : 1;}
//loop
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
#define brep(i, n) for (int i = n - 1; i >= 0; --i)
//omission
#define eb emplace_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())

/*
 n = 2を考える
 k = 1
 
 2 0
 0 1
 
 k = 2
 操作するとともにk減らしてく
 k = 1で2 0にくるようにすればいい
 
 1 2
 2 0
 0 1
 
 これを続ける
 ただし、n = 2を採用するとai ≤ 10^16 + 1000を満たさない
 
 n = 50に拡張するだけ
 
 */
int main() {
    //cast caution
    //look constraints always
    cin.tie(0); ios::sync_with_stdio(false);
    ll K; cin >> K;
    int n = 50;
    cout << n << endl;
    int table[50][50] = {0};
    rep(j, 50) table[0][j] = j;
    rrep(i, 1, 50) {
        int key = -1, val = inf;
        rep(j, 50) {
            if (table[i - 1][j] < val) {
                key = j; val = table[i - 1][j];
            }
        }
        rep(j, 50) {
            if (j == key) table[i][j] = table[i - 1][j] + n;
            else table[i][j] = table[i - 1][j] - 1;
        }
    }
    //rep(i, 50) {rep(j, 50) cout << table[i][j] << " "; cout << endl;}
    if (K < 50) {rep(j, 50) cout << table[K][j] << " "; cout << endl;}
    else {
        rep(j, 50) {if (j) cout << " ";
            ll k = K - j;
            ll b = k / n;
            if (k % n) {b = (k + (n - 1)) / n + n - k % n;}
            cout << b;}
        cout << endl;
    }
}



