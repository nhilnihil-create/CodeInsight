#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  ll ans=0;
  ll vec[n][2];
  for(int i=n-1;i>=0;i--){
    cin>>vec[i][0]>>vec[i][1];
  }
  ll x;
  for(int i=0;i<n;i++){
    x=(vec[i][1]-(vec[i][0]+ans)%vec[i][1])%vec[i][1];
    ans+=x;
  }
  cout<<ans<<endl;
}