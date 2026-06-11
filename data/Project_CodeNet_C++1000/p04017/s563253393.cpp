#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 17;
int main()
{
	int n,i,j;
	scanf("%d",&n);
	ll p[n+2];
	for(i=1;i<=n;++i)
	{
		scanf("%lld",&p[i]);
	}
	ll dist;
	scanf("%lld",&dist);
	int l[n+1],r[n+1];
	for(i=1;i<=n;++i)
	{
		l[i] = -1;
		int le = 1,ri = i;
		while(le <= ri)
		{
			int mid = (le+ri)/2;
			if(p[i] - p[mid] <= dist)
			{
				l[i] = mid;
				ri = mid-1;
			}
			else	le = mid+1;
		}
	}
	for(i=1;i<=n;++i)
	{
		r[i] = -1;
		int le = i,ri = n;
		while(le <= ri)
		{
			int mid = (le+ri)/2;
			if(p[mid] - p[i] <= dist)
			{
				r[i] = mid;
				le = mid+1;
			}
			else	ri = mid-1;
		}
	}
	int left[N][n+1],right[N][n+1];
	for(i=1;i<=n;++i)
	{
		left[0][i] = l[i];
		right[0][i] = r[i];
	}
	for(i=1;i<N;++i)
	{
		for(j=1;j<=n;++j)
		{
			left[i][j] = left[i-1][left[i-1][j]];
			right[i][j] = right[i-1][right[i-1][j]];
		}
	}
	int q,x,y;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d %d",&x,&y);
		if(x < y)		swap(x,y);
		int le = 1,ri = n,ans=n;
		while(le<=ri)
		{
			int mid = (le+ri)/2;
			int cur = x;
			for(i=0;i<N;++i)
			{
				if(((1<<i) & mid) != 0)
				{
					cur = left[i][cur];
				}
			}
			if(cur<=y)
			{
				ans = mid;
				ri = mid-1;
			}
			else	le = mid+1;
		}
		printf("%d\n",ans);
	}
}