#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

const ll MAXN=1e9;

long long ruijou(ll n, ll k){
    if(k==0) return 1;
    ll x=k/2;
    long long t=ruijou(n,x);
    
    if(k%2==1) return n*t*t;
    else return t*t;
}

bool ask(ll N){
    cout<<"? "<<N<<endl;
    char x; cin>>x;
    if(x=='Y') return true;
    else return false;
}

int main(){
    ll ans;
    if(ask(ruijou(10,10))){
        ll OK=-1,NG=10;
        while(NG>OK+1){
            ll MID=(OK+NG)/2;
            if(ask(2*ruijou(10,MID))) NG=MID;
            else OK=MID;
        }
        ans=ruijou(10,NG);
    }

    else{
        ll NG=10, OK=-1;
        while(NG>OK+1){
            ll MID=(OK+NG)/2;
            if(ask(ruijou(10,MID))) OK=MID;
            else NG=MID;
        }
        
        ll x=OK;
        NG=ruijou(10,x);
        OK=NG*10-1;
        while(OK>NG+1){
            ll MID=(OK+NG)/2;
            ll A=MID*10;
            if(ask(A)) OK=MID;
            else NG=MID;
        }
        ans=OK;
    }
    cout<<"! "<<ans<<endl;
}