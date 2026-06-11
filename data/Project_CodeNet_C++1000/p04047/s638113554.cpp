#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<set>
#include<map>
using namespace std;
#define mp make_pair
#define ll long long
#define re register
typedef pair<int,int> pii;
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=210;
int n,a[N];
int main()
{
	n=gi()<<1;for(int i=1;i<=n;i++)a[i]=gi();
	sort(a+1,a+n+1);int ans=0;
	for(int i=1;i<=n;i+=2)ans+=a[i];
	printf("%d\n",ans);
	return 0;
}
