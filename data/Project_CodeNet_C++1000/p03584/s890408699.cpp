#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 50;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

int main() {
    cin>>N>>K;
    vec a(N), b(N);
    rep(i,N) cin>>a[i]>>b[i];
    ll ans = 0;
    rep(i,30){
        if((K>>i)&1){
            ll k = (K ^ (1LL<<i)) | ((1LL<<i) - 1), temp = 0;
            //cout<<k<<endl;
            rep(j,N) if((k | a[j]) == k) temp += b[j];
            ans = max(ans, temp);
        }
    }
    ll t = 0;
    rep(j,N) if((K | a[j]) == K) t += b[j];
    ans = max(ans, t);
    cout<<ans<<endl;
}