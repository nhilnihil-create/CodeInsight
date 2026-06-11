#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1000000007;
ll power(ll x, ll  y)  
{  
    ll res = 1;     // Initialize result  
    x = x % mod;
    y=y%mod;
    while (y > 0)  
    {  
        if (y & 1)  
            res = ((res%mod)*(x%mod)) % mod;  
        y = y>>1; // y = y/2  
        x = ((x%mod)*(x%mod)) % mod;  
    }  
    return res%mod;  
}  
  
int main(){
    ll n,m;
    cin>>n;ll a[n+2];ll hash[200005]={0};
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(n%2==0)
    {
    	if(a[0]!=1) {cout<<"0\n";return 0;}
    	if(a[1]!=1) {cout<<"0\n";return 0;}
    	for(int i=2,j=3;i<n;i+=2,j+=2){
    	if(a[i]==j && a[i+1]==j){}else {cout<<"0\n";return 0;}}
    	
    }
    else
    {
    	if(a[0]!=0) {cout<<"0\n";return 0;}
    	for(int i=1,j=2;i<n;i+=2,j+=2){
    	if(a[i]==j && a[i+1]==j){}else {cout<<"0\n";return 0;}}
    }

   ll ans = 1;
	for (ll i = 1; i <=(n/2); i++) {
		ans *= 2;
		ans %= mod;
	}
	cout << ans << endl;
    }
    
    
   

    
