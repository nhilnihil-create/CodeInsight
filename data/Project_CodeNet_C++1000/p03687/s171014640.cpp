#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    string s;
    string S; cin >> S;
    s = S;
    int ans = 1e5;
    for(int i = 0; i < 26; i++) {
        char c = (char)('a'+i);
        int cnt = 0;
        S = s;
        while(1) {
            bool ok = true;
            int M = S.size();
            char pre = S[0];
            REP(i,M) {
                if(pre != S[i]) ok = false;
                pre = S[i];
            }
            if(ok) break;
            string T = "";
            REP(i,M-1) {
                if(S[i] == c || S[i+1] == c) T += c;
                else T += S[i];
            }
            cnt++;
            //cout << T << endl;
            S = T;
        }
        chmin(ans,cnt);
    }
    cout << ans << endl;
}