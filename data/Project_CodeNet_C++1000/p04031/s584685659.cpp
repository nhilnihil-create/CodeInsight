#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=100+10;
const int inf=1<<30;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    int ans1=0,ans=inf; 
    for(int j=-100;j<=100;j++)
	{
		ans1=0;
		for(int i=1;i<=n;i++)
		{
			int k=a[i]-j;
			ans1+=k*k;
		}
		ans=min(ans,ans1);
	}
	cout<<ans<<"\n";
}