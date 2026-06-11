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
    vector<string> S(3);
    REP(i,3) cin >> S[i];
    int turn = 0;
    while(1) {
        if(S[turn] == "") {
            cout << (char)('A'+turn)<< endl;
            return 0; 
        }
        char next = S[turn][0];
        S[turn].erase(S[turn].begin());
        turn = next-'a';
    }
}