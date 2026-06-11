#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 


	
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll x;
	cin>>x;
	
	ll val = 1+4*2*x;
	
	val = sqrt(val);
	
	val-=1;
	val = val/2;
	
	if(((val*(val+1))/2) == x)
	{
		cout<<val<<endl;
	}
	else
	{
		cout<<val+1<<endl;
	}
	
}

