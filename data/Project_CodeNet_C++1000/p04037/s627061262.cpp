#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,a[N],mx,le;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	mx=-1;
	for(int i=1;i<=n;++i) 
		if(a[i]<i) { mx=i-2; break; }
	if(!(~mx)) mx=n-1;
	for(int i=n;i>=1;--i)
		if(a[i]>mx) { le=i; break; }
	bool ans=((a[mx+1]-mx)&1)&((le-mx)&1);
	if(ans) puts("Second");
	else puts("First");
	return 0;
}