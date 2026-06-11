#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e18;
const double PI=3.1415926535897932;
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



int main(){
    ll N; cin>>N;
    vec d(N+2,0);
    REP(i,1,N+1) cin>>d[i];
    vec x(N+1);
    REP(i,1,N+1) x[d[i]]=i;
    ll ans=0;
    set<ll> f,m;
    f.insert(0); f.insert(N+1);
    m.insert(0); m.insert(-N-1);
    REP(i,1,N+1){
        ans+=i*(*f.upper_bound(x[i])-x[i])*(*m.upper_bound(-x[i])+x[i]);
        f.insert(x[i]); m.insert(-x[i]);
    }
    cout<<ans<<endl;

}