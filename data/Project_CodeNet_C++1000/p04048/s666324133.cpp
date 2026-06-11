#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,x;
  cin>>n>>x;
  ll ans=n;
  n-=x;
  if(x>n) swap(x,n);
  while(1){
   ll k=n/x;
   n-=x*k;
   ans+=x*2*k;
   if(x>n) swap(x,n);
   if(n==x||x==0){
    cout<<ans-n<<endl;
    return 0;
}
}
  return 0;
}