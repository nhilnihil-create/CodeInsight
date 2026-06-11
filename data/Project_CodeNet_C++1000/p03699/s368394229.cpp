#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main(){
  int n; cin>>n;
  vector<int> v(n);
  int ans=0;
  rep(i,n){
    cin>>v.at(i);
    ans+=v.at(i);  
    if(v.at(i)%10==0){v.at(i)=0;}
  }
  sort(v.begin(),v.end());
  while(v.at(0)==0){
    v.erase(v.begin());
    if(v.size()==0)break;
  }
  
  if(ans%10!=0){cout<<ans;}
  else if(v.size()==0)cout<<0;
  else{cout<<ans-v.at(0);}
}