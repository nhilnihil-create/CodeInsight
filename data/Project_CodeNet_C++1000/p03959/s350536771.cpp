#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); 

  int N;
  cin>>N;
  vector<int>T(N),A(N);
  for(int i=0;i<N;i++)cin>>T[i];
  for(int i=0;i<N;i++)cin>>A[i];

  if(N==1){
    if(T[0]==A[0])cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
  }

  vector<bool>tb(N,false),ab(N,false);
  tb[0]=true;
  ab[N-1]=true;
  for(int i=1;i<N;i++){
    if(T[i]!=T[i-1])tb[i]=true;
  }
  for(int i=N-2;i>=0;i--){
    if(A[i]!=A[i+1])ab[i]=true;
  }
  
  ll ans=1;
  bool ng=false;
  for(int i=0;i<N;i++){
    if(tb[i]&&ab[i]){
      if(T[i]!=A[i])ng=true;
    }
    else if(tb[i]){
      if(T[i]>A[i])ng=true;
    }
    else if(ab[i]){
      if(T[i]<A[i])ng=true;
    }
    else{
      ans*=min(T[i],A[i])%MOD;
      ans%=MOD;
    }
  }
  if(ng)cout<<0<<endl;
  else cout<<ans<<endl;
  return 0;
}
