#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int N,M,a[1<<17];
long ans=9e18,now;
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	vector<pair<int,int> >E;
	for(int i=1;i<N;i++)
	{
		if(a[i-1]<a[i])E.push_back(make_pair(a[i-1],a[i]));
		else E.push_back(make_pair(a[i-1]-M,a[i]));
		now+=(a[i]-a[i-1]+M)%M;
	}
	for(int i=0;i<N-1;i++)E.push_back(make_pair(E[i].first+M,E[i].second+M));
	sort(E.begin(),E.end());
	priority_queue<pair<int,int> >P;
	int id=0;
	for(int x=0;x<M;x++)
	{
		now-=P.size();
		while(id<2*N-2&&E[id].first<x)
		{
			P.push(make_pair(-E[id].second,E[id].second-E[id].first));
			now+=E[id].second-x+1;
			now-=E[id].second-E[id].first;
			id++;
		}
		ans=min(ans,now);
		while(!P.empty()&&-P.top().first==x)
		{
			now+=P.top().second-1;
			P.pop();
		}
	}
	cout<<ans<<endl;
}