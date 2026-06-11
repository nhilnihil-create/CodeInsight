#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define N 200002
int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+2*n);
	int ans=0;
	for(int i=1;i<=2*n;i+=2)ans+=a[i];
	printf("%d\n",ans);
}
