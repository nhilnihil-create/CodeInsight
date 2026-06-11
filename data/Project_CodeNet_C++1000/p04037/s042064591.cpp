#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define N 1000200
using namespace std;
inline int read(){
	int x=0,w=0;char ch=getchar();
	while (!isdigit(ch))w|=ch=='-',ch=getchar();
	while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return w?-x:x;
}
int n,a[N];
signed main(){
	n=read();
	for (int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n,greater<int>());
	for (int i=1;i<=n;++i)
		if (i+1>a[i+1]){
			int ans=0;
			for (int j=i+1;a[j]==i;++j)ans^=1;
			if (ans||((a[i]-i)&1))puts("First");
			else puts("Second");
			break;
		}
	return 0;
}