// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const char s[4]={'R','G','B','Y'};

int main() {
	int n=read(),m=read(),k=read();
	for (int i=0;i<n;++i) {
		for (int j=0;j<m;++j) {
			int x=(m+i+j)/k&1,y=(m+i-j)/k&1;
			putchar(s[x<<1|y]);
		}
		puts("");
	}
	return 0;
}
// cy