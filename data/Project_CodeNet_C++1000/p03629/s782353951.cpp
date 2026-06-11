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

const int N=200000+10;

int n; char s[N];
int nxt[N][26],dp[N];

int main() {
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=n;i;--i) {
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		nxt[i][s[i]-'a']=i;
	}
	memset(dp,0x3f,sizeof(dp));
	for (int i=n;i;--i)
		for (int j=0;j<26;++j) {
			if (!nxt[i][j]) { dp[i]=1; break; }
			dp[i]=min(dp[i],dp[nxt[i][j]+1]+1);
		}
	for (int l=dp[1],p=1;l;--l) {
		if (l==1) {
			for (int i=0;i<26;++i)
				if (!nxt[p][i]) { putchar(i+'a'); break; }
		} else {
			for (int i=0;i<26;++i) {
				if (dp[p]==dp[nxt[p][i]+1]+1) {
					putchar(i+'a'),p=nxt[p][i]+1; break;
				}
			}
		}
	}
	return 0;
}