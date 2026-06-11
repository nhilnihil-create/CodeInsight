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
    string S;
    cin >> S;
    int N = S.size();
    veci dir(4);
    REP(i,N) {
        if(S[i] == 'N') dir[0] = 1;
        else if(S[i] == 'S') dir[1] = 1;
        else if(S[i] == 'E') dir[2] = 1;
        else if(S[i] == 'W') dir[3] = 1;
    }
    if(dir[0] == dir[1] && dir[2] == dir[3]) cout << "Yes" << endl;
    else cout << "No" << endl;
}