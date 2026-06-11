#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],cnt=0;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]),cnt+=(a[i]&1);
	if(cnt>=3)return puts("Impossible"),0;	
	if(m==1)
	{
		if(a[1]==1)cout<<1<<endl<<1<<endl<<1;
		else cout<<a[1]<<endl<<2<<endl<<a[1]-1<<" "<<1<<endl;
	}
	else
	{
		bool flag=0;vector<int>ans;
		for(int i=1;i<=m;i++)
		{
			if(a[i]&1)
			{
				if(!flag)swap(a[i],a[1]),flag=1;
				else
				{
					swap(a[i],a[m]);
					break;
				}
			}
		}
		for(int i=1;i<=m;i++)cout<<a[i]<<" ";puts("");
		for(int i=1;i<=m;i++)
		{
			if(a[i]&1)
			{
				if(i==1)ans.push_back(a[i]+1);
				else if(i==m)if(a[i]>1)ans.push_back(a[i]-1);
			}
			else
			{
				if(i==1)ans.push_back(a[i]+1);
				else
				{
					if(i!=m)ans.push_back(a[i]);
					else 
					{
						if(a[i]>1)ans.push_back(a[i]-1);
					}
				}
			}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d\n",ans[i]);
	}
}