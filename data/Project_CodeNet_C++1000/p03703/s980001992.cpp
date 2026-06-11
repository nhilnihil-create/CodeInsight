#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> P;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

const int MaxN=220000;
int bit[MaxN];
void add(int a, int w) {
for (int x = a; x <= MaxN; x += (x & -x)) bit[x] += w;
}
int sum(int a) {
 int ret = 0;
for (int x = a; x > 0; x -= (x & -x)) ret += bit[x];
 return ret;
}

int main(){
    ll N,K; cin>>N>>K;
    vec d(N+1,0);
    rep(i,N){
        ll x; cin>>x;
        x-=K;
        d.at(i+1)=d.at(i)+x;
    }

    vector<P> So;
    rep(i,N+1) So.pb(mp(d.at(i),i));
    
    sort(ALL(So));
    //rep(i,N+1) cout<<So.at(i).first<<' '<<So.at(i).second<<endl;

    vec A(N+1);
    rep(i,N+1) A.at(So.at(i).second)=i;
    //rep(i,N+1) cout<<A.at(i)<<endl;
    ll ans=0;
    rep(i,N+1) {
        ans+=sum(A.at(i)+50);
        add(A.at(i)+50,1);
    }
    cout<<ans<<endl;



    

}