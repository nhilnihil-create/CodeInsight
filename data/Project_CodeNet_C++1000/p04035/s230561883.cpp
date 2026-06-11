#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	
ll n,L;
cin>>n>>L;
vector<ll>v(n),ans(n-1);
ll sum=0;
for(ll i=0;i<n;i++)
{
	cin>>v[i];
	sum+=v[i];
}

	for(ll f=0,l=n-1,j=0;j<n-1;j++)
	{
		if(v[f]+v[f+1]<v[l]+v[l-1])
		{
			if(sum>=L)
			sum-=v[f];
			else
			{
				cout<<"Impossible";
				return 0;
			}
			ans[j]=f+1;
			f++;
			
			
		}
		else
		{
			if(sum>=L)
			sum-=v[l];
			else
			{
				cout<<"Impossible";
				return 0;
			}
			ans[j]=l;
			l--;
		}
		
	}
	
	cout<<"Possible\n";
	for(auto x:ans)cout<<x<<"\n";
	



}