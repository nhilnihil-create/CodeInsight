#include<iostream>
#include<cstdio>
#include<algorithm>
#define M 100010
using namespace std;
int n,a[M],ton[M];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),ton[a[i]]++;
	sort(a+1,a+1+n);
	int sz=ton[a[1]];
	if(sz>2) {
		puts("Impossible");return 0;
	}
	if(sz==2&&a[n]%2==0) {
		puts("Impossible");return 0;
	}
	for(int i=a[1]+(sz&1);i<=a[n];i++)
		if(ton[i]<2) {
			puts("Impossible");return 0;
		}
	puts("Possible");
	return 0;
}