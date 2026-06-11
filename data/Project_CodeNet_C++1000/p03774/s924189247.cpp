#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
#define INF 1e9
using ll=long long;
using namespace std;


int main()
{
	int N,M;
	cin>>N>>M;
	vector<pair<int,int>> ab(N);
	rep(i,N)
	{
		int a,b;
		cin>>a>>b;
		ab[i]=make_pair(a,b);
	}
	vector<pair<int,int>> cd(M);
	rep(i,M)
	{
		int c,d;
		cin>>c>>d;
		cd[i]=make_pair(c,d);
	}
	rep(i,N)
	{
		int min_v=INF;
		int min_i=-1;
		rep(j,M)
		{
			if(min_v>abs(ab[i].first-cd[j].first)+abs(ab[i].second-cd[j].second))
			{
				min_v=abs(ab[i].first-cd[j].first)+abs(ab[i].second-cd[j].second);
				min_i=j;
			}
		}
		cout<<min_i+1<<endl;
	}
	return 0;
}
