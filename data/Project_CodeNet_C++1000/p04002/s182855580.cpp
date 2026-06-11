#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>a;
long long h,w,n,sum,ans[1000003],ans1[13];
int a1,b1;
int main()
{
	cin>>h>>w>>n;
	for(int k=1; k<=n; k++)
	{
		scanf("%d%d",&a1,&b1);
		for(int i=max(3,a1); i<=a1+2; i++)
			for(int j=max(b1,3); j<=b1+2; j++)
				if(i<=h&&j<=w)
				{
					if(a[make_pair(i,j)]==0)
						sum++,a[make_pair(i,j)]=sum,ans[sum]=1;
					else
						ans[a[make_pair(i,j)]]++;
				}
	}
	for(long long i=1; i<=sum; i++)
		ans1[ans[i]]++;
	ans1[0]=(h-2)*(w-2)-sum;
	for(long long i=0; i<=9; i++)
		cout<<ans1[i]<<endl;
	return 0;
}