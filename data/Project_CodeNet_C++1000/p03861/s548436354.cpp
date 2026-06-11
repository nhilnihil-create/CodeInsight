#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll a,b,x;
  cin>>a>>b>>x;
  ll ans;
  ans=b/x-a/x+((a%x==0)?1:0);
  cout<<ans<<endl;
  return 0;
}