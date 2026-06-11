#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define fi first
#define se second
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    string S;cin >> S;
    vector<char> V;
    REP(i,S.size()) V.pb(S[i]);
    sort ALL(V);
    ll cnt = 0;
    vector<ll> W;
    REP(i,V.size()-1){
        if(V[i] == V[i+1]) cnt++;
        else{
			cnt++;
            W.pb(cnt);
            cnt = 0;
        }
    }
	cnt++;
	W.pb(cnt);
	ll N = S.size();
    ll L = N*(N - 1 ) / 2;
	ll ans = 0;
    REP(i,W.size()){
        ans += W[i]*(W[i]-1)/2;
    }
    cout << L - ans + 1 << endl;
}
