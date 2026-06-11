#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 const ll inf=1e9+7;
ll dp[50][3000];
int main()
{
    fast;
    
    ll a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    
    if(a[2]==a[0]+a[1])
    cout<<"Yes";
    else
    cout<<"No";

}

		
	
	
	
	
