 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
  ll a,b,x,ans=0;
  cin>>a>>b>>x;
  if(a==0) ans = 1 + (b/x);
  else ans = (b/x) - ((a-1)/x);
  
  cout<<ans<<endl;
}