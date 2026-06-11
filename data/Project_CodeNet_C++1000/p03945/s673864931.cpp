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

const int N=100000+10;

int n; char s[N];

int main() {
	scanf("%s",s+1); n=strlen(s+1);
	int ans=0;
	for (int i=1;i<n;++i) ans+=s[i]!=s[i+1];
	printf("%d\n",ans);
	return 0;
}