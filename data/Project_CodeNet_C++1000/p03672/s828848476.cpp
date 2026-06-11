//url:
//problem name: 

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
    string T = S;
    S = T.substr(0,N-1);
    int cnt = N-1;
    while(1) {
        //cout << cnt << endl;
        T = S.substr(0,cnt);
        if(T.size() %2 == 0 && T.substr(0,cnt/2) == T.substr(cnt/2,cnt/2)) {
            cout << T.size() << endl;
            return 0;
        }
        cnt--;
    }
}
