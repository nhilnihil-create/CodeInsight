#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mkp make_pair
const int N=1e5+10;
map<pii ,int > g;
unsigned long long ans[20];
int main()
{
	int h,w,n;
	scanf("%d%d%d",&h,&w,&n);
	ans[0]=1LL*(h-2)*(w-2);
	for(int a,b,i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		for(int j=0;j<3;j++)
		for(int k=0;k<3;k++)
		if(a+j<=h&&a+j>=3&&k+b<=w&&k+b>=3)
		{	
			ans[ g[mkp(a+j,b+k)] ]--;
			ans[ ++g[mkp(a+j,b+k)] ]++;
		}
	}
	for(int i=0;i<10;i++)
		cout<<ans[i]<<endl;
	return 0;
}