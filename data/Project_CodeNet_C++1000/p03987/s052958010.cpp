#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,long long> > v;
set<int> s;

main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		long long a;
		scanf("%lld",&a);
		v.push_back(make_pair(a,i+1));
	}
	sort(v.begin(),v.end());
	long long ans=0;
	ans+=(((v[0].second-1)*(n-v[0].second))+(n))*1;
	//printf("%lld\n",ans);
	s.insert(v[0].second);
	for(int i=1;i<n;i++)
	{
		long long nw=v[i].first;
		long long po=v[i].second;
		set<int>::iterator it=s.lower_bound(po);
		int lm,rm;
		if(it==s.end())
		{
			it--;
			lm=*it;
			lm++;
			rm=n;
		}
		else
		{
			rm=*it;
			rm--;
			if(it==s.begin())
			{
				lm=1;
			}
			else
			{
				it--;
				lm=*it;
				lm++;
			}
		}
		//printf("%d %d\n",lm,rm);
		ans+=(((po-lm)*(rm-po))+(rm-lm+1))*nw;
		//printf("%lld\n",(((po-lm)*(rm-po))+(rm-lm+1))*nw);
		s.insert(po);
	}
	printf("%lld",ans);
}