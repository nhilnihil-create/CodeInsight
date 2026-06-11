#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<string>
#include<math.h>
#include<stdio.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
const int MAXN=10010;
const ll long_inf=9223372036854775807;
const int int_inf=2147483647;
inline ll read() {
	ll c=getchar(),Nig=1,x=0;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')Nig=-1,c=getchar();
	while(isdigit(c))x=((x<<1)+(x<<3))+(c^'0'),c=getchar();
	return Nig*x;
}
char s[500005];
char t[500005];
int ans1[500005];
int ans2[500005];
int main() {
	int ans=0;
	scanf("%s%s",s+1,t+1);
	for(int i=1; s[i]; i++) {
		if(s[i]=='B')
			ans1[i]=ans1[i-1]+2;
		else
			ans1[i]=ans1[i-1]+1;
	}
	for(int i=1; t[i]; i++) {
		if(t[i]=='B')
			ans2[i]=ans2[i-1]+2;
		else
			ans2[i]=ans2[i-1]+1;
	}
	int T=read();
	int a,b,c,d;
	for(int i=0; i<T; i++) {
		a=read(),b=read(),c=read(),d=read();
		int TEMP1=ans1[b]-ans1[a-1];
		int TEMP2=ans2[d]-ans2[c-1];
		if((TEMP1%3)==(TEMP2%3))
			puts("YES");
		else
			puts("NO");
	}
}
