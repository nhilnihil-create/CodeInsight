#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define x first
#define y second

namespace perform
{
	typedef std::pair<int,int> pii;
	const int N=510,M=N*N;
	pii s[N];
	int t[M];
	int n,m;
	void initialize()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i].x),s[i].y=i;
		std::sort(s+1,s+n+1);
		m=n*n;
	}
	bool work()
	{
		t[0]=t[m+1]=-1;

		int ind=0,id;
		for(int i=1;i<=n;i++)
		{
			id=s[i].y;
			for(int tmp=id-1;tmp--;)
			{
				for(;t[ind];ind++);
				t[ind]=id;
			}
			if(ind>=s[i].x)return 0;
			t[s[i].x]=id;
		}

		ind=m+1;
		for(int i=n;i;i--)
		{
			id=s[i].y;
			for(int tmp=n-id;tmp--;)
			{
				for(;t[ind];ind--);
				t[ind]=id;
			}
			if(ind<=s[i].x)return 0;
		}

		return 1;
	}
	void solve()
	{
		initialize();
		if(!work())printf("No\n");
		else
		{
			printf("Yes\n");
			for(int i=1;i<=m;i++)
				printf("%d ",t[i]);
			printf("\n");
		}
	}
}
int main()
{
	perform::solve();
	return 0;
}
