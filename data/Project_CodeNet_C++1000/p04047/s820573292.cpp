#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,a[301];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+2*n);
	for(int i=1;i<=2*n;i+=2) ans+=a[i];
	printf("%d",ans);
	return 0;
}