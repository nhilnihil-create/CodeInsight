#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define int long long
#define MAXN 2005

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int n,x,val[MAXN],minn[MAXN][MAXN];

signed main(){
	read (n,x);
	for (Int i = 1;i <= n;++ i) read (val[i]);
	for (Int i = 1;i <= n;++ i){
		minn[i][i] = val[i];
		for (Int j = i + 1;j <= n;++ j) minn[i][j] = min (minn[i][j - 1],val[j]);
	}
	int ans = 0x7f7f7f7f7f7f7f;
	for (Int i = 0;i <= n;++ i){
		int res = 0;
		for (Int j = 1;j <= n;++ j){
			int k = j - i;
			if (k <= 0) res += min (minn[n + k][n],minn[1][j]);
			else res += minn[k][j];
		}
		ans = min (ans,res + i * x);
	}
	write (ans),putchar ('\n');
	return 0;
} 