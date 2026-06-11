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
using namespace std;
typedef long long LL;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int a[1000000];
//odd(a)为序列a中奇数个数
//要使得所有数全相等，那么相等关系至少为n-1对
//(n-odd(a))/2+(n-odd(b))/2>=n-1
//odd(a)+odd(b)<=2
//当a中奇数个数>2时无解
//否则我们把a的奇数放到两侧然后构造答案
int main()
{
	int m=gi(),n=gi(),i;
	for (i=1;i<=n;i++) a[i]=gi();
	for (i=2;i<n;i++) if (a[i]&1) { swap(a[i],a[1]); break; }
	for (i=2;i<n;i++) if (a[i]&1) { swap(a[i],a[n]); break; }
	for (i=2;i<n;i++) if (a[i]&1) return puts("Impossible"),0;
	if (n==1)
		if (m==1) puts("1\n1\n1");
		else printf("%d\n2\n1 %d\n",a[1],a[1]-1);
	else {
		for (i=1;i<=n;i++) printf("%d ",a[i]);putchar(10);
		printf("%d\n",n-(a[1]==1));
		if (a[1]!=1) printf("%d ",a[1]-1);
		for (i=2;i<n;i++) printf("%d ",a[i]);
		printf("%d",a[n]+1);
	}
	return 0;
}
