#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 1LL<<60;
const ll MOD = 1e9 + 7;


int main() {
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    ll tate = abs(sy-ty);
    ll yoko = abs(sx - tx);
    for (ll i = 0;i<yoko;i++) {
        cout << 'R';
    }
    for (ll i = 0;i<tate;i++) {
        cout << 'U';
    }
    for (ll i = 0;i<yoko;i++) {
        cout << 'L';
    }
    for (ll i = 0;i<tate;i++) {
        cout << 'D';
    }
    cout << 'L';
    for (ll i = 0;i<tate+1;i++) {
        cout << 'U';
    }
    for (ll i = 0;i<yoko+1;i++) {
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    for (ll i = 0;i<tate+1;i++) {
        cout << 'D';
    }
    for (ll i = 0;i<yoko+1;i++) {
        cout << 'L';
    }
    cout << 'U';
}