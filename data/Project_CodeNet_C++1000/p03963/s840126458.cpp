#include <iostream>
#define ll long long 
using namespace std;
ll power(ll k,ll n){
 ll prod=1;
 while(n){
  if(n%2) prod=prod*k;
   k=k*k;
   n/=2;
 }
 return prod;


}
int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll n,k; cin>>n>>k;
 ll ans=k*power(k-1,n-1);
 cout<<ans<<endl;
 return 0;
}
