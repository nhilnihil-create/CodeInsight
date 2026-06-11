#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	map<int,int> m;
	rep(i,N)
	{
		int a;
		cin>>a;
		for(int j=-1;j<=1;j++)
		{
			m[a+j]++;
		}
	}
	int ans=0;
	for(auto p : m)
	{
		ans=max(ans,p.second);
	}
	cout<<ans<<endl;
	return 0;
}
