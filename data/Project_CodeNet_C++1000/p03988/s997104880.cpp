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

int main(){
    ll N; cin>>N;
    vec d(N);
    rep(i,N) cin>>d.at(i);
    sort(ALL(d));
    reverse(ALL(d));
    ll K=d.at(0);
    vec co(101,0);
    rep(i,N) co.at(d.at(i))++;
    bool able=true;
    rep(i,K+1){
        ll x=(2*K+1-i)/2;
        if(co.at(x)<=0) able=false;
        co.at(x)--;
    }
    ll MIN=(K+1)/2;
    rep(i,MIN+1) if(co.at(i)>0) able=false;
    if(able) cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    
}