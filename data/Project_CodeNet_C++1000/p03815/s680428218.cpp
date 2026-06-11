#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  ll x;
  cin>>x;
  ll ans=0;
  ans+=x/11*2;
  x%=11;
  if(x==0){
    cout<<ans<<endl;
  }
  else if(x<=6){
    cout<<ans+1<<endl;
  }
  else{
    cout<<ans+2<<endl;
  }
}