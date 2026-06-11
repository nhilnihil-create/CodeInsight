//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long,long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long,long>>;

int main() {
    int N; cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    int x = 0;
    REP(i,N) {
        if(S[i] == 'I') x++;
        else x--;
        chmax(ans,x);
    }
    cout << ans << endl;
}