#include<bits/stdc++.h>
using namespace std;
const long long maxn=100+5;
long long n,m,d,ans1,ans2=0,cnt1,cnt2;
long long a[maxn],C[maxn][maxn];
bool cmp(long long x,long long y)
{
	return x>y;
}
void init()
{
    C[0][0]=1;
    C[1][0]=1;
    C[1][1]=1;
    for(int i=1;i<=50;i++)
	{
        C[i][0]=1;
        for(int j=1;j<=i;j++)
        C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
}
int main()
{
	init();
	cin>>n>>m>>d;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=m;i++)
	{
		ans1+=a[i];
	}
	for(long long i=1;i<=n;i++) 
	{
		if(a[i]==a[m]) 
		{
			cnt1++;
		}
	}    
	for(long long i=1;i<=m;i++)  
	{
		if(a[i]==a[m]) 
		{
			cnt2++;	
		}
	}
    if(a[1]==a[m]) 
	{
		for(long long i=m;i<=min(cnt1,d);i++) 
		{
			ans2+=C[cnt1][i];
		}	
	}
    if(a[1]!=a[m])  ans2=C[cnt1][cnt2];
    printf("%.6lf\n%lld",(double)ans1/m,ans2);
	return 0;
}