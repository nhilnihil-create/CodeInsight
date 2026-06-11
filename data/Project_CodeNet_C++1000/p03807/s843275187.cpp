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
inline int gi()
{
	int f=1,sum=0;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=(sum<<3)+(sum<<1)+ch-'0';ch=getchar();}
	return f*sum;
}
const int N=100010;
int n,a[N],ans;
int main()
{
	n=gi();
	for(int i=1;i<=n;i++)a[i]=gi();
	for(int i=1;i<=n;i++)ans^=a[i]&1;
	puts(ans?"NO":"YES");
	return 0;
}
