#include<bits/stdc++.h>
using namespace std;
int n,a[100002],i,j;
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (i=1;i<=n;i++)
		if (i+1>a[i+1]) break;
	for (j=i+1;j<=n && a[j]==i;j++);
	puts((a[i]-i&1)|!(j-i&1)?"First":"Second");
}