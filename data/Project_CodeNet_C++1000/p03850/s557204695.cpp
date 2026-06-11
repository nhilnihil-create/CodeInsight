#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
using namespace std;
typedef long long LL;
const int N=2e5;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int a[N];
LL b[N];
int main()
{
	int n=gi()-1,i,m=0,x;char c;
	LL sum=gi(),ans=-1LL<<60;
	for (i=1;i<=n;i++) {
		while ((c=getchar())!='+'&&c!='-');
		sum+=x=gi();
		if (c=='+') b[m]+=x; else a[++m]=x;
	}
	for (i=1;i<=m;i++) {
		ans=max(ans,sum-(a[i]+b[i])*2);
		sum-=a[i]*2;
	}
	cout<<max(ans,sum)<<endl;
	return 0;
}
