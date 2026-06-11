#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, d=0;
int a[N];
map<int, int> m;

void quit()
{
	cout<<"Impossible";
	exit(0);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		d=max(d, a[i]);
	}	
	int odd=0;
	for(auto &it:m)
	{
		if(it.first==(d+1)/2)
		{
			if(d%2==0 && it.second!=1)
				quit();
			else if(d%2==1 && it.second!=2)
				quit();
			continue;
		}
		odd+=(it.second==1);
	}
	if(n%2==0 && odd>0)
		quit();
	if(n%2 && odd>1)
		quit();
	int prv=m.begin()->first;
	if(prv!=(d+1)/2)
		quit();
	for(auto &it:m)
	{
		if(it.first-prv>1)
		{
			cout<<"Impossible";
			return 0;
		}
		prv=it.first;
	}
	cout<<"Possible";
	return 0;
}
