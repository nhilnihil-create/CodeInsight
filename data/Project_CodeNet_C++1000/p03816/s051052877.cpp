#include<iostream>
#include<cstdio>
#include<algorithm> 
#define N 123456
using namespace std;
int n,a[N],ans;
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		if(a[i] == a[i-1]) ans++;
	if(ans & 1) ans++;
	printf("%d\n",n-ans);
	return 0;
}