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
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end())
#define pb push_back
#define mp make_pair
#define MODP(A,B) A=(A+B)%mod
typedef pair<ll,ll> P;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

const ll MAXN=100001;

ll d[MAXN][20];

int main(){
    ll N; cin>>N;
    vec x(N);
    rep(i,N) cin>>x.at(i);
    
    ll Le; cin>>Le;
    rep(i,MAXN) rep(j,20) d[i][j]=INF;
    rep(i,N) d[i][0]=(upper_bound(ALL(x),x.at(i)+Le)-x.begin())-1;
   
    
    
    rep(k,19){
        if(d[0][k]==N-1) break;
        rep(i,N) {
            if(d[i][k]>=N-1) break;
            d[i][k+1]=d[d[i][k]][k];
        }
    }
   
   
    
    ll Q; cin>>Q;
    vec ans;
    rep(i,Q){
        ll L,R; cin>>L>>R;
        L--; R--;
        if(L>R) swap(L,R);
        ll A=0;
        while(true){
            if(d[L][0]>R) {A++; break;}
            ll* x=upper_bound(d[L],d[L]+20,R);
            ll X=(ll)(x-d[L])-1;
            A+=(1<<X);
            L=d[L][X];
            if(L==R) break;
        }
        ans.pb(A);
    }
    /*rep(i,N){
        cout<<i<<':';
        rep(k,19){
            if(d[i][k]>N) break;
            cout<<d[i][k]<<' ';
        }
        cout<<endl;
    }*/
    rep(i,Q) cout<<ans.at(i)<<endl;
}