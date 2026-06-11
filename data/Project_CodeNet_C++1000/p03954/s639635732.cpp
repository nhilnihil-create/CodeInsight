
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<bitset>
#include<map>
using namespace std;
inline int re_ad()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();return x*f;
}
inline int ma(int x,int y){return x>y?x:y;}
inline int mi(int x,int y){return x>y?y:x;}
int n,a[200010],A[200010],cnt=0;struct node{int num,ii;}B[200010];
bool cmp(node x,node y){return x.num<y.num;}
inline bool check(int k)
{
	for(register int i=0;i<n-1;i++)
	{
	if(a[n-i]<=k&&a[n-i-1]<=k||a[n+i]<=k&&a[n+i+1]<=k)return true;
	if(a[n-i]>k&&a[n-i-1]>k||a[n+i]>k&&a[n+i+1]>k)return false;
	}
	return a[1]<=k;
}
int main()
{
	n=re_ad();n=n*2-1;
	for(int i=1;i<=n;i++)a[i]=re_ad(),B[i].num=a[i],B[i].ii=i;
	sort(B+1,B+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
	if(B[i].num!=B[i-1].num)++cnt;
	A[cnt]=B[i].num;a[B[i].ii]=cnt;
	}
	int l=1,r=cnt,mid;
	n=n+1>>1;
	while(l<r)
	{
	int mid=l+r>>1;if(check(mid))r=mid;else l=mid+1;
	}
	cout<<A[l]<<endl;return 0;
}
