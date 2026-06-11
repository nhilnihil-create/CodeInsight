#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define REP(a,b,c) for(int a=b;a<=c;a++)
#define re register
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
typedef pair<int,int> pii;
#define mp make_pair
#define int ll
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=200010;
int n,a[N];
ll sum,x[N];
int nxt(int id){return id%n+1;}
signed main()
{
	n=gi();ll get=1ll*n*(n+1)/2;
	for(int i=1;i<=n;i++)a[i]=gi(),sum+=a[i];
	if(sum%get)return puts("NO"),0;
	ll t=sum/get,s=0;
	for(int i=1;i<=n;i++)
	{
		ll del=a[i]-a[nxt(i)]+t;
		if(del<0||del%n)return puts("NO"),0;
		x[i]=del/n;
	}
	for(int i=1;i<=n;i++)s+=x[i];
	puts(s==t?"YES":"NO");
	return 0;
}
