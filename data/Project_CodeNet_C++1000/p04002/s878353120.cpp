#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1e5+10;
int a,b,n,cnt; 
ll h,w,ans[10],all;
P res[N*9];
bool ok(int x,int y)
{
	return x>1&&x<h&&y>1&&y<w;
}
map<P,int>num;
int main()
{
	scanf("%lld%lld%d",&h,&w,&n);
	ans[0]=(h-2)*(w-2);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a,&b);
		num[P(a,b)]=1;
		for(int j=-1;j<=1;++j)
		{
			for(int k=-1;k<=1;++k)
			{
				if(ok(a+j,b+k))
					res[cnt++]=P(a+j,b+k);
			}
		}
	}
	if(cnt)
	{
		sort(res,res+cnt);
		cnt=unique(res,res+cnt)-res;
		for(int i=0;i<cnt;++i)
		{
			a=res[i].first,b=res[i].second;
			int now=0;
			for(int j=-1;j<=1;++j)
			{
				for(int k=-1;k<=1;++k)
				{
					if(num.count(P(a+j,b+k)))
						now++;
				 } 
			}
			ans[now]++,ans[0]--; 
		}
	}
	for(int i=0;i<=9;++i)
	printf("%lld\n",ans[i]);
	return 0;
} 