#include<bits/stdc++.h>
using namespace std;
 
long long n; int h1=1001,r1=1000,h2=2001,r2=2000,stp,a[105],ans[10005];
void solve(long long n){
	if (n==1 || n%2==0){
		if (n>1) solve(n-1);
		stp++;
		ans[++r1]=stp; ans[--h2]=stp;
	} else{
		solve(n/2);
		stp++; ans[++r1]=stp; ans[++r2]=stp;
	}
}
int main(){
	scanf("%lld",&n); solve(n);int i;
	printf("%d\n",r1-h1+r2-h2+2);
	for (i=h1; i<=r1; i++) printf("%d ",ans[i]);
	for (i=h2; i<=r2; i++) printf("%d ",ans[i]);
	return 0;
}