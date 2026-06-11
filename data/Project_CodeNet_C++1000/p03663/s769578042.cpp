// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

int pw[10];

char query(ll x) {
	printf("? %lld\n",x),fflush(stdout);
	char s[5]; scanf("%s",s); return s[0];
}

void answer(int x) {
	printf("! %d\n",x),fflush(stdout);
}

int main() {
	for (int i=pw[0]=1;i<10;++i) pw[i]=10*pw[i-1];
	if (query(pw[9])=='Y') {
		for (int i=9;i;--i)
			if (query(pw[i]-1)=='N') { answer(pw[i]); return 0; }
		answer(1); return 0;
	}
	int len=0;
	for (;len<10;++len)
		if (query(pw[len])=='N') break;
	--len;
	if (len==9) { answer(pw[9]); return 0; }
	int L=pw[len],R=pw[len+1]-1;
	while (L<R) {
		int mid=(L+R)>>1;
		if (query(10ll*mid)=='N') L=mid+1;
		else R=mid;
	}
	answer(L);
	return 0;
}