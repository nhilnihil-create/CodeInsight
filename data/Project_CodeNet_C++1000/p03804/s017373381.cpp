#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    vector<vector<char>> b(m, vector<char>(m));
    rep(i, n) {
        string s; cin >> s;
        rep(j, n) a[i][j] = s[j];
    }
    rep(i, m) {
        string s; cin >> s;
        rep(j, m) b[i][j] = s[j];
    }
    rep(i, n-m+1) {
        rep(j, n-m+1) {
            bool fl = true;
            rep(k, m) {
                rep(l, m) {
                    if(a[i+k][j+l] != b[k][l]) fl = false;
                }
            }
            if(fl) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}