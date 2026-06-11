#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }
ll rep(ll N,ll P){
    if(P==0) return 1;
    if(P%2==0){
      ll t=rep(N,P/2);
      return t*t%MOD;
    }
    return N*rep(N,P-1);
  }


int main(){
    ll N,ans;
    bool f=true;
    cin>>N;
    vector<ll> A(N+1,0);
    for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        A[a]++;
    }
    for(ll i=0;i<N;i++){
        if(N%2==0){
            if(i%2==0&&A[i]!=0) f=false;
            if(i%2==1&&A[i]!=2) f=false;
        }else{
            if(i==0&&A[i]!=1) f=false;
            if(i!=0&&i%2==0&&A[i]!=2) f=false;
            if(i%2==1&&A[i]!=0) f=false;
        }
    }
    ans=rep(2,N/2);
    ans%=MOD;
    if(f) cout<<ans<<endl;
    else cout<<"0"<<endl;
}