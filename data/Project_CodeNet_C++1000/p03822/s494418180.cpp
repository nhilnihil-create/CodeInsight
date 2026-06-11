#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)

lli dp [100100];
bool vis[100100];

vector<lli> G[100100];

lli func(lli now){
	if(vis[now])return dp[now];

	vis[now]=true;
	multiset<lli> s;

	for(auto e:G[now]){
		s.insert(func(e));
	}

	lli cnt = 0;
	for(auto e:s){
		if(e>cnt)cnt = e;
		cnt++;
	}

	return dp[now] = cnt;
}

int main()
{
	lli n;
	cin>>n;

	REP(i,1,n){
		lli a;
		cin>>a;
		a--;
		G[a].push_back(i);
	}

	cout<<func(0)<<endl;
	
}