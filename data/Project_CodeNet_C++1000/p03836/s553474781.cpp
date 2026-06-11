#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using P = pair <int, int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
const int mod = 1000000007;

ll dp[100100];
int main() {
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    rep(i,tx-sx){
        cout << 'R';
    }
    rep(i,ty-sy){
        cout << 'U';
    }
    cout << 'R';
    rep(i,ty-sy+1){
        cout << 'D' ;
    }
    rep(i,tx-sx+1){
        cout << 'L';
    }
    cout << 'U' ;
    rep(i,ty-sy){
        cout << 'U';
    }
    rep(i,tx-sx){
        cout<<'R';
    }
    cout << 'U';
    rep(i,tx-sx+1){
        cout << 'L';
    }
    rep(i,ty-sy+1){
        cout << 'D';
    }
    cout <<'R';

}