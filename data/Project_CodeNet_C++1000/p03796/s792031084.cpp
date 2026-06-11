#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p=1000000007;
ll factfastaf(ll n)
{
     if (n >= p) 
        return 0; 
  
    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = (result * i) % p ; 
  
    return result; 
 }
  

int main()
{
	ll n;
   cin>>n;
  ll r= factfastaf(n);
  cout<<(r);
  return 0;
}
    