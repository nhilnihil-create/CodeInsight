#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
   #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 ll t,a,b; cin>>t;
 ll x=1,y=1; 
 while(cin>>a>>b){

 
    ll da=((x-1)/a)+1;
    ll db=((y-1)/b)+1;
    ll dc=max(da,db);
    x=a*dc; y=b*dc;
  
  
 }
 cout<<x+y<<endl;
 return 0;
}
