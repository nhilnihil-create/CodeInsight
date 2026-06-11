#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int p=1;
	while (a[p]-(n-p)<=0)
	p++;
	if (a[p]%2==(n-p)%2 || (a[p-1]==n-p+1 && count(a+1,a+p,a[p-1])%2))
	printf("First");
	else
	printf("Second");
}