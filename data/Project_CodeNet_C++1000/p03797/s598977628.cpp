#include<bits/stdc++.h>
using namespace std;
using ll=long long;



int main(){
  ll n,m,i,ans;
  cin >> n >> m;
  if(n*2<=m){
    ans=n;
    m=m-n*2;
    ans+=m/4;
  }else{
    ans=m/2;
  }
  cout << ans << endl;
  return 0;
}
