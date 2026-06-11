#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll mod = 1000000007 ;

int main()
{
 ll ans = 1 , n;
 cin >> n;

 for(ll i=1; i<=n; i++)
 {
     ans = ((ans%mod)*(i%mod))%mod;
 }


 cout << ans << endl;
}
