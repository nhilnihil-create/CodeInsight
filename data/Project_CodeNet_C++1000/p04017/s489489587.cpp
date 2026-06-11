#include<bits/stdc++.h>
using namespace std;
int n,l,m,a[100003],x,y,b[100003][103],ans,l1,r1,mid;
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	cin>>l>>m;
	for(int i=1; i<=n-1; i++)
	{
		l1=i+1,r1=n;
		while(l1<=r1)
		{
			mid=(l1+r1)/2;
			if(a[mid]-a[i]>l)
				r1=mid-1;
			else
				l1=mid+1;
		}
		b[i][0]=r1;
	}
	for(int j=n; j>=1; j--)
		for(int i=1; b[b[j][i-1]][i-1]!=0; i++)
			b[j][i]=b[b[j][i-1]][i-1];
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		ans=0;
		if(x>y)
			swap(x,y);
		while(x<y)
		{
			for(int i=0; i==0||b[x][i-1]!=0; i++)
				if(b[x][i]==y)
				{
					x=b[x][i],ans+=(1<<i);
					break;
				}
				else if(b[x][i]>y||b[x][i]==0)
				{
					if(i==0)
					{
						x=y,ans+=1;
						break;
					}
					x=b[x][i-1],ans+=(1<<(i-1));
					break;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}