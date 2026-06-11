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
    string S; cin >> S;
    int N = S.size();
    vector<pair<char,int>> R;
    int i = 0;
    while(i < N) {
        char c = S[i];
        int cnt = 1;
        while(S[i+cnt] == c) cnt++;
        R.push_back(make_pair(c,cnt));
        i += cnt;
    }
    int ans = N;
    int rest_S = 0;
    REP(i,R.size()-1) {
        if(R[i].first == 'S' && R[i+1].first == 'T') {
            R[i].second += rest_S;
            int ret = min(R[i].second,R[i+1].second);
            R[i].second -= ret;
            R[i+1].second -= ret;
            rest_S = R[i].second;
            ans -= 2*ret;
        }
    }
    cout << ans << endl;
}