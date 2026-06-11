#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N,C,K;
	cin>>N>>C>>K;
	vector<int> T(N);
	rep(i,N) cin>>T[i];
	sort(T.begin(),T.end());
	int prev=T[0];
	int cnt=1;
	int i=1;
	int ans=0;
	while (i<N)
	{
		if(prev+K>=T[i]&&cnt<C)
		{
			cnt++;
		}
		else
		{
			ans++;
			cnt=1;
			prev=T[i];
		}
		i++;
	}
	cout<<ans+1<<endl;
	return 0;
}
