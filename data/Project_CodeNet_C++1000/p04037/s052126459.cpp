#include<bits/stdc++.h>
using namespace std;
#define RI register int
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
const int N=100005;
int n,a[N];
int cmp(int x,int y) {return x>y;}
int main()
{
	n=read();
	for(RI i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n,cmp);
	for(RI i=1;i<=n;++i)
		if(i+1>a[i+1]) {
			int j=i+1;while(a[j]==i) ++j;
			int ans=(j-i-1)&1;
			ans|=(a[i]-i)&1;
			if(ans) puts("First");
			else puts("Second");
			return 0;
		}
	return 0;
}