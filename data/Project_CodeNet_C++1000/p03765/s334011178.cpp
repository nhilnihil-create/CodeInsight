#include <bits/stdc++.h>
const int N=100005;
char s[N],t[N];
int a[N],b[N],Q,n,m,l1,r1,l2,r2;
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1);
	for (int i=1;i<=n;i++) a[i]=a[i-1]+1+(s[i]=='A');
	for (int i=1;i<=m;i++) b[i]=b[i-1]+1+(t[i]=='A');
	scanf("%d",&Q);
	while (Q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if ((a[r1]-a[l1-1])%3==(b[r2]-b[l2-1])%3) 
			puts("YES");
		else puts("NO");
	}
	return 0;
}