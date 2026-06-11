#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int ans[1000000];
int cnt[505];
int mm[1000005];

signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
	if(fopen("INPUT.txt","r"))
	{
	freopen ("INPUT.txt" , "r" , stdin);
	freopen ("OUTPUT.txt" , "w" , stdout);
	}
#endif  

	int n;
	cin>>n;
	int x[n+1];
	for(int i=1;i<=n;i++)
		cin>>x[i];
	set<pair<int,pair<int,int> > >s;
	set<pair<int,pair<int,int> > >d;
	for(int i=1;i<=n;i++)
	{
		mm[x[i]]=i;
		ans[x[i]]=i;
		if(i>1)
			s.insert({x[i],{i-1,i}});
		if(i<n)
			d.insert({-x[i],{n-i,i}});
	}
	int ini=1;
	while (ini<=n*n)
	{
		if(ans[ini])
		{
			ini++;
			continue;
		}
		if(s.empty())
			break;
		pair<int,pair<int,int> > j=*s.begin();
		ans[ini++]=j.second.second;
		s.erase(j);
		j.second.first--;
		if(j.second.first)
			s.insert(j);
	}

	ini=n*n;
	while (ini>=1)
	{
		if(ans[ini])
		{
			ini--;
			continue;
		}
		if(d.empty())
			break;
		pair<int,pair<int,int> > j=*d.begin();
		ans[ini--]=j.second.second;
		d.erase(j);
		j.second.first--;
		if(j.second.first)
			d.insert(j);
	}

	bool flag=true;
	for(int i=1;i<=n*n;i++)
	{
		cnt[ans[i]]++;
		if(mm[i])	
		{
			if(cnt[ans[i]]!=mm[i])
			{
				flag=false;
				break;
			}
		}
	}
	if(flag)
	{
		cout<<"Yes\n";
		for(int i=1;i<=n*n;i++)
			cout<<ans[i]<<" ";
	}
	else
	{
		cout<<"No";
	}
	

}
