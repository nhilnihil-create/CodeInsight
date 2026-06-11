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
//#define P pair<ull,ull>
//#define PP pair<int,pair<int,int> >
//#define mp(a,b) make_pair(a,b)
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
int n, v[N];

inline int gcd(int x,int y) { 
	int t;
	while( y ) t = x, x = y, y = t % y;
	return x;
}

inline bool check(bool x) { 
	int n1 = 0, n2 = 0, d = 0; bool f1 = 0;
	rep(i,1,n) { 
		if( v[i] & 1 ) n1++; else n2++;
		if( v[i] == 1 ) f1 = 1;
	}
	if( n2 & 1 ) return x;
	if( n1 > 1 || f1 ) return x ^ 1;
	rep(i,1,n) if( v[i] & 1 ) v[i]--;
	rep(i,1,n) d = gcd(v[i],d);
	rep(i,1,n) v[i] /= d;
	return check(x^1);
}

int main() {
	n = read();
	rep(i,1,n) v[i] = read();
	if( !check(0) ) puts("First");
	else puts("Second");
	return 0; 
}