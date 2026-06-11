  
#include <bits/stdc++.h>
#include<vector>
#include<set>
#define ll long long
using namespace std;
 

ll gcd(ll a,ll b){
 if(b == 0) return a;
 return gcd(b,a%b);
 }

 ll lcm(ll a,ll b){
 ll g = gcd(a,b);
 return a / g * b; 
}
int main() {
	
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t,a,b,c,d,n,m,k,sum,i,j;
       string str;
     cin>>t;
      ll ans=1LL;
     while(t--)
     {
     	cin>>n;
     	ans=lcm(ans,n);
	 }
     cout<<ans<<endl;
     
     
     
  return 0;
}
