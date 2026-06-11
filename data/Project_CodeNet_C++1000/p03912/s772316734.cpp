#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    vector<int> x(m, 0), dou(m, 0);
    rep(i,n){
        int a;
        cin >> a;
        cnt[a]++;
        x[a%m]++;
    }
    for(auto p : cnt){
        if(p.second >= 2){
            dou[p.first%m] += p.second / 2;
        }
    }
    int ans = 0;
    rep(i,m){
        if(i == (m-i)%m){
            ans += x[i] / 2;
            x[i] %= 2;
        }
        else{
            int add = min(x[i], x[m-i]);
            ans += add;
            x[i] -= add;
            x[m-i] -= add;
        }
        if(dou[i] > 0 && x[i] >= 2){
            int add2 = min(x[i]/2, dou[i]);
            ans += add2;
            x[i] -= add2 * 2;
        }
    }
    cout << ans << endl;
    return 0;
}