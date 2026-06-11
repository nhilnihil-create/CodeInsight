#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100002
using namespace std;
char s[N],t[N];
int q,i,ls,lt,a[N],b[N];
int main()
{
	scanf("%s%s%d",s+1,t+1,&q);
	ls=strlen(s+1);
	lt=strlen(t+1);
	for(i=1;i<=ls;i++) a[i]=(int)(s[i]-'A'+1);
	for(i=1;i<=lt;i++) b[i]=(int)(t[i]-'A'+1);
	for(i=1;i<=ls;i++) a[i]+=a[i-1];
	for(i=1;i<=lt;i++) b[i]+=b[i-1];
	for(i=1;i<=q;i++){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if((a[r1]-a[l1-1])%3==(b[r2]-b[l2-1])%3) puts("YES");
		else puts("NO");
	}
	return 0;
}