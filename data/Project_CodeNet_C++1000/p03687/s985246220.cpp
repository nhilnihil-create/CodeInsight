#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    int cnt = 0;
    map<char, int> mci;
    rep(i, s.size()){
        mci[s[i]]++;
    }
    int max = 0;
    int ans = 100;
    char key;
    for(auto u : mci){
        //cout << u.first << "  " << u.second << endl;
        int now1 = 0;
        rep(i,s.size()){
            int now = 0;
            int j = i;
            while(j < s.size()){
                if(s[j] == u.first) break;
                j++;
                now++;
            }
            chmax(now1,now);
            i = j;
        }
        chmin(ans,now1);
    }
    cout << ans << endl;
    return 0;
}