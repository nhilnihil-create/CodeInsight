#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
ll dp[50][3000];
int main()
{
    fast;
    
	ll n,k,ans=0;

cin>>n>>k;


ans=k*pow(k-1,n-1);
cout<<ans;
}

		
	
	
	
	
