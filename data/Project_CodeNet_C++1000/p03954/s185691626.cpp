/*******************************
Author:Morning_Glory
LANG:C++
Created Time:2019年07月23日 星期二 10时12分43秒
*******************************/
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
const int maxn = 200005;
//{{{cin
struct IO{
	template<typename T>
	IO & operator>>(T&res){
		res=0;
		bool flag=false;
		char ch;
		while((ch=getchar())>'9'||ch<'0')	 flag|=ch=='-';
		while(ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^'0'),ch=getchar();
		if (flag)	 res=~res+1;
		return *this;
	}
}cin;
//}}}
int n,m,l,r;
int a[maxn],b[maxn],c[maxn];
bool flag=true;
bool check (int x)
{
	int tl=m,tr=m,ans=c[m];
	c[0]=c[1],c[n+1]=c[n];
	for (;tl>=1&&c[tl]!=c[tl-1]&&c[tr]!=c[tr+1];--tl,++tr)	ans^=1;
	return ans;
}
int main()
{
	cin>>m;
	n=2*m-1;
	for (int i=1;i<=n;++i)	cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	l=1,r=n;
	while (l<r){
		int mid=(l+r)/2+1;
		for (int i=1;i<=n;++i)	c[i]=a[i]>=b[mid];
		if (check(mid))	l=mid;
		else	r=mid-1;
	}
	printf("%d\n",b[l]);
	return 0;
}
