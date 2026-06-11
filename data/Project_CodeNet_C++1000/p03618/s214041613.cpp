#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef vector<double> Vec;
typedef vector<Vec> Mat;
typedef pair<ll,ll> P;
typedef pair<double,ll> Pd;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;
typedef priority_queue<Pd,vector<Pd>,greater<Pd>> Pd_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
const double DEL=1e-3;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod
#define CHECK cout<<"arrived"<<endl

ll C2(ll x){
    return x*(x-1)/2;
}
int main(){
    string S; cin>>S;
    vec d(26,0);
    ll N=S.size();
    rep(i,N) d[S[i]-'a']++;
    ll ans=C2(N);
    rep(i,26) ans-=C2(d[i]);
    ans++;
    cout<<ans<<endl;
}