#include<bits/stdc++.h>
#define C getchar()
#define LL long long
using namespace std;
inline int read() {
	int num = 0;
	char c=C;
	for(;c<'0' || c>'9';c=C);
	for(;c>='0'&&c<='9';c=C) num = (num << 1) + (num << 3) + (c ^ 48);
	return num;
}

int n;
int a[200010],st[200010];
int l[200010],r[200010];

int main() {
	
	n = read();
	LL ans = 0;
	for(int i=1;i<=n;++i) a[i] = read();
	int top = 0;
	l[1] = 1;st[++top] = 1;
	for(int i=2;i<=n;++i) {
		while (a[i] < a[st[top]] && top) -- top;
		l[i] = st[top] + 1;
		st[++top] = i;
	}
	top = 1;
	r[n] = n;st[top] = n;
	for(int i=n-1;i>=1;--i) {
		while (a[i] < a[st[top]] && top) -- top;
		if (top == 0) r[i] = n;
		 else r[i] = st[top] - 1;
		st[++top] = i;
	}
	
	for(int i=1;i<=n;++i) {
		LL tmp = (LL)(i - l[i] + 1) * (LL)(r[i] - i + 1);
		ans += (LL)tmp * (LL)a[i];
	}
	
	printf("%lld",ans);
	return 0;
}
