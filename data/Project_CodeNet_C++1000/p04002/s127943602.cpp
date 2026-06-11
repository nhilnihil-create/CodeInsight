#include<cstdio>
#include<cctype>
#include<map>
using namespace std;
int read()
{
	int f,c,x;
	while(!isdigit(c=getchar())&&c!='-'); c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while(isdigit(c=getchar())) x=(x<<3)+(x<<1)+c-'0'; return f?-x:x;
}
int h,w,n,X,Y;
long long ans[11];
map<pair<int,int>,int>ma;
int main()
{
	h=read(); w=read(); n=read();
	ans[0]=1ll*(h-2)*(w-2);
	for(int x,y,i=1;i<=n;i++)
	{
		x=read(); y=read();
		for(int j=0;j<3;j++)
		{
			X=x+j;
			for(int k=0;k<3;k++)
			{
				Y=y+k;
				if(X>=3&&X<=h&&Y>=3&&Y<=w)
				{
					ans[ma[make_pair(X,Y)]]--;
					ans[++ma[make_pair(X,Y)]]++;
				}
			}
		}
	}
	for(int i=0;i<=9;i++) printf("%lld\n",ans[i]);
	return 0;
}