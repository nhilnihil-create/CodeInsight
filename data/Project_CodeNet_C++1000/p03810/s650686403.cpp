/*
ID:xmydada1
LANG:C++
TASK:
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],b[N],m,n,ans=0,ans1=0,ans2=0,p,c=0,x;
#define reg register
inline int read() {
	reg int s = 0, t = 0;
	reg char ch = getchar();
	while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
	while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return t ? -s : s;
}

inline void print(reg long long x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + 48);
}
int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(reg int i=1; i<=n; i++) {
		a[i]=read();
	
	}
	while(1) {
			for(reg int i=1; i<=n; i++) {
		if(a[i]%2==1)ans++;
		else ans1++;
		if(a[i]==1)ans2++;
	}
		if(ans2==1&ans1==n-ans2) {
			if(ans1%2==0)c^=1;
			break;
		} else if(ans1%2==1)break;
		else if(ans>1&&ans1%2==0) {
			c=c^1;break;
		}
		else 
		{
			for(int i=1;i<=n;i++)
			if(a[i]%2==1)a[i]--;
			x=a[1];
			for(int i=2;i<=n;i++)
			x=__gcd(x,a[i]);
			for(int i=1;i<=n;i++)
			a[i]/=x;
			c^=1;
		}
		ans=0;ans1=0;ans2=0;

	}
    if(c==0)printf("First\n");
    else printf("Second\n");
	return 0;
}
