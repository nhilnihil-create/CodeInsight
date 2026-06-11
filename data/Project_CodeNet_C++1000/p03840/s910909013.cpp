#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll i,o,t,j,l,s,z;
  cin>>i>>o>>t>>j>>l>>s>>z;
  ll ans=o;
  ll knum=0;
  if(i%2==1) knum++;
  if(j%2==1) knum++;
  if(l%2==1) knum++;
  if(knum==0||knum==3) ans+=i+j+l;
  else if(knum==1) ans+=i+j+l-1;
  else{
    if(i!=0&&j!=0&&l!=0) ans+=i+j+l-1;
    else ans+=i+j+l-2;
  }
  cout<<ans<<endl;
}
