#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int a[N];

int main() {
	int n;
	scanf("%d",&n);
	int mn,mx;
	mn=1e9,mx=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),mn=min(mn,a[i]),mx=max(mx,a[i]);
	int cnt=0;
	for(int i=1;i<=n;i++) if(a[i]==mn) cnt++;
	if(mx-mn>1) puts("No");
	else if(mn==mx&&n/mx>1) puts("Yes");
	else if(mn!=mx&&cnt+1<=mx&&mx<=cnt+(n-cnt)/2) puts("Yes");
	else if(mn==mx&&mx==n-1) puts("Yes");
	else puts("No");
}