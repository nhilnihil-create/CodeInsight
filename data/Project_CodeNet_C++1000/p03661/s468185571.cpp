#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};

ll modfact(ll x){
  if(x==1) return 1;
  else return (x*modfact(x-1))%mod;
}

int main(){
  int N;
  cin>>N;
  vector<ll> a(N);
  ll sum=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    sum+=a[i];
  }

  ll x=a[0];
  ll ans=1e17;

  for(int i=1;i<N;i++){
    ans=min(ans,abs(sum-2*x));
    x+=a[i];
  }
  cout<<ans<<endl;
  return 0;
}


