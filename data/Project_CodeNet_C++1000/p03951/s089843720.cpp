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
    int N;
    cin >> N;
    string S,T; cin >> S >> T;
    int cnt = 0;
    REP(i,N) {
        if(S.substr(i,N-i) == T.substr(0,N-i)) {
            cout << S.substr(0,i).size() + T.size() << endl;
            return 0;
        }
    }
    cout << 2*N << endl;
}