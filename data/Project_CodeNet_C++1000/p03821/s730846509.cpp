#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
int main() 
{
	 ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
		int n;
		cin>>n;
		ll a[n],b[n];
		for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	ll	int ans=0;
		for(int i=n-1;i>=0;i--)
		{
			if((a[i]+ans)%b[i]==0)
			continue;
			
			ans+=b[i]-(a[i]+ans)%b[i];
		}
		cout<<ans<<endl;
			
				 
	
}
