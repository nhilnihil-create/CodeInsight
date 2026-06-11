#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n,p;
  cin>>n>>p;
  ll ans=1;
  int odd=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    odd+=a%2;
    ans*=2;
  }
  if(odd==0){
    if(p==0){
      cout<<ans<<endl;
    }
    else{
      cout<<0<<endl;
    }
  }
  else{
    cout<<ans/2<<endl;
  }
  return 0;
}
