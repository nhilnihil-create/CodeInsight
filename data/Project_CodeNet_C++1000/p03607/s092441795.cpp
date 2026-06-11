#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N;
  ll A;
  cin>>N;
  
  map<ll,ll>v;
  for(int i=0;i<N;i++){
    cin>>A;
    v[A]++;
  }
  ll ans=0;
  for(auto x:v){
    if(x.second%2!=0)ans++;
  }
  cout<<ans<<endl;
}
    
