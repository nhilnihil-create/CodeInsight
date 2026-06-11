#include<bits/stdc++.h>

using namespace std;
  
#define ll long long int

int m=1e9+7;

int main()
{
	  #ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);

	  #endif
	  int n;
	  cin>>n;
	  // ll arr[n];
	  map<ll,ll> mp;
	  for(int i=0;i<n;i++)
	  {
	  		ll temp;
	  		cin>>temp;
	  		mp[temp]++;	
	  }
	  ll res=1;
	  for(auto i: mp)
	  {
	  		if(n%2==0)
	  		{

	  			if(i.first%2!=1 || i.second!=2)
	  			{
	  				cout<<0;
	  				return 0;
	  			}
	  			else
	  				res=(res*2)%m;
	  		}
	  		else
	  		{
	  			if(i.first%2!=0 || i.second!=2)
	  			{
	  				if(i.first==0 && i.second==1);
	  				
	  				else
	  				{
	  					cout<<0;
	  					return 0;
	  				}

	  			}
	  			else
	  			{
	  				res=(res*2)%m;
	  				// cout<<i.second<<"  ";
	  			}
	  		}
	  }
	  cout<<res;

}