#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,a[N];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int p;
	for (int i=1;i<=n;i++) if (i+1>a[i+1]) {p=i;break;}
	int q=p;
	while (q<n&&a[q+1]>=p) q++;
	int tag=0;
	if (p==q) tag=(a[p]-p)&1;
	else if (a[p]==p) tag=(q-p)&1;
	else tag=((a[p]-p)&1)|((q-p)&1);
	if (tag) puts("First");
	else puts("Second");
	return 0;
}