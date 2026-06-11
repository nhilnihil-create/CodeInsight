#include<bits/stdc++.h>

using namespace std;

#define ll long long

int m=1e9+7;

int main()
{
	  #ifndef ONLINE_JUDGE
	  freopen("input.txt", "r", stdin);
	  freopen("output.txt", "w", stdout);

	  #endif
	  ll limit,sum;
	  cin>>limit>>sum;
	  if(sum>3*limit)
	  		cout<<0;
	  else
	  {
	  		ll res=0;
	  		for(int i=0;i<=limit;i++)
	  		{
	  			if(sum-i<=2*limit && sum-i>=0)
	  			{
	  				for(int j=0;j<=limit;j++)
	  				{
	  					if(sum-i-j<=limit && sum-i-j>=0)
	  						res++;
	  				}
	  			}

	  		}
	  		cout<<res;
	  }
}