#include <bits/stdc++.h>
using namespace std;

const int M=100;
int a[M];

int main()
{
	int n; scanf("%d",&n);
	n*=2;
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i+=2)
		ans+=a[i];
	printf("%d\n",ans);
	return 0;
}