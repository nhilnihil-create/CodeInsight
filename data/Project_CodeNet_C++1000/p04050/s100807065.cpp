#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#define rep(i,j,k) for(register int i = j; i <= k; i++) 
#define dow(i,j,k) for(register int i = j; i >= k; i--)
#define fi first
#define se second
//#define P pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define ull unsigned long long
using namespace std;

inline int read() { 
	int s = 0, t = 1; char c = getchar();
	while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
	while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
	return s * t;
}

const int N = 1e5+5;
int a[N], b[N], c[N], ret = 0;

int main() {
	int n = read(), m = read(), x;
	rep(i,1,m) { 
		x = read();
		if( x & 1 ) a[++a[0]] = x;
		else b[++b[0]] = x;
	}
	
	if( n == 1 ) { 
		puts("1");
		puts("1");
		puts("1");
		return 0;
	}
	if( m == 1 ) { 
		printf("%d\n", n);
		puts("2");
		printf("%d %d\n", n-1,1);
		return 0;
	}
	
	if( a[0] >= 3 ) puts("Impossible");
	else { 
		if( !a[0] ) { 
			rep(i,1,b[0]) printf("%d ", b[i]); puts("");
			
			ret = b[0];
			printf("%d\n", ret);
			
			rep(i,1,b[0]) printf("%d ", i == 1 ? b[i] - 1 : (i == b[0] ? b[i] + 1 : b[i]));
			puts("");
		} else if( a[0] == 1 ) { 
			printf("%d ", a[1]); rep(i,1,b[0]) printf("%d ", b[i]); puts("");
			
			ret = ((a[1] - 1) > 0) + b[0];
			printf("%d\n", ret);
			
			if( a[1] - 1 ) printf("%d ", a[1] - 1);
			rep(i,1,b[0]) printf("%d ", i == b[0] ? b[i] + 1 : b[i]);
			puts("");
		} else { 
			printf("%d ", a[1]); rep(i,1,b[0]) printf("%d ", b[i]); printf("%d ", a[2]); puts(""); 
			
			ret = ((a[1] - 1) > 0) + b[0] + 1;
			printf("%d\n", ret);
			
			if( a[1] - 1 ) printf("%d ", a[1] - 1);
			rep(i,1,b[0]) printf("%d ",b[i]);
			printf("%d ", a[2] + 1);
			puts("");
		}
	}
	return 0;
}