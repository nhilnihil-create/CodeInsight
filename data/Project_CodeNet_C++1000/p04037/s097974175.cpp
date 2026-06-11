#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,x,y,t,a[100010];
int main(){
	scanf("%d",&n);for (i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n,greater<int>());
	while (a[t]>=t)t++;t--;
	if ((a[t]-t)%2==0){
		j=0;
		for (;a[t+j]>=t;j++);
		if (j%2==1)printf("Second\n");
		else printf("First\n");
	}
	else printf("First\n");
	return 0;
}