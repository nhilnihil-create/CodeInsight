#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using lint=int64_t;
using namespace std;

int N,W;
int kinds;
lint wl[4];
map<lint,vector<lint>> m;
int num[4];
lint ans;

void dfs(int d)
{
	if(d==kinds)
	{
		lint wsum=0;
		for(int i=0;i<kinds;i++)
			wsum+=wl[i]*num[i];
		if(wsum>W)
			return;

		lint tans=0;
		for(int i=0;i<kinds;i++)
			for(int j=0;j<num[i];j++)
				tans+=m[wl[i]][j];
		ans=max(ans,tans);
		return;
	}

	for(int i=0;i<=m[wl[d]].size();i++)
	{
		num[d]=i;
		dfs(d+1);
	}

	return;
}

int main()
{
	cin >> N >> W;
	for(int i=0;i<N;i++)
	{
		lint w,v;
		cin >> w >> v;
		m[w].push_back(v);
	}

	for(auto&& j:m)
	{
		wl[kinds]=j.first;
		kinds++;
		sort(j.second.begin(),j.second.end(),greater<lint>());
	}

	dfs(0);

	cout << ans << endl;
	return 0;
}
