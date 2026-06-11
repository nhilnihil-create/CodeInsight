#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
//const ll MOD=(ll)998244353;
const ll INF=(ll)1e18+10;
const double PI = 2.0*acos(0);
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void solve(int ca){
    string S; cin>>S;
    int N=S.length();
    ll ans=(ll)N*(N-1)/2+1;
    vector<int> cnt(26,0);
    for (int i = 0; i < N; ++i) {
        cnt[S[i]-'a'] ++;
    }
    for (int i = 0; i < 26; ++i) {
        ans-=(ll)cnt[i]*(cnt[i]-1)/2;
    }

    cout<<ans<<endl;
}

//#define MULTI
int main() {
#ifdef MULTI
    int N; cin>>N;
    for (int i = 0; i < N; ++i) {
        solve(i+1);
    }
#else
    solve(0);
#endif
    return 0;
}
