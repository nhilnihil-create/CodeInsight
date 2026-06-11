#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int A,B,C; cin >> A >> B >> C;
    int k = 1;
    REP(i,B) {
        if((A%B)*(k%B)%B == C) {
            cout << "YES" << endl;
            return 0;
        } else ++k;
    }
    cout << "NO"  << endl;
}