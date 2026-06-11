#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int SX, SY, TX, TY;
    cin >> SX >> SY >> TX >> TY;
    rep(i, 0, TY - SY) {
        cout << "U";
    }
    rep(i, 0, TX - SX) {
        cout << "R";
    }
    rep(i, 0, TY - SY) {
        cout << "D";
    }
    rep(i, 0, TX - SX + 1) {
        cout << "L";
    }
    rep(i, 0, TY - SY + 1) {
        cout << "U";
    }
    rep(i, 0, TX - SX + 1) {
        cout << "R";
    }
    cout << "D";
    cout << "R";
    rep(i, 0, TY - SY + 1) {
        cout << "D";
    }
    rep(i, 0, TX - SX + 1) {
        cout << "L";
    }
    cout << "U" << endl;
    return 0;
}