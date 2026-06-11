#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());
#define ADD(a,b) a=(a+b)%mod

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

ll N,A,B,C,D;

int main(){
    cin>>N>>A>>B>>C>>D;
    N--;
    A=abs(A-B);
    ll x=D-C, y=D+C;
    ll R=N*D, L=N*C;
    bool able=false;
    while(true){
        if(A>R) break;
        if(L<=A && A<=R) {able=true; break;}
        A+=y;
    }
    if(able) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}