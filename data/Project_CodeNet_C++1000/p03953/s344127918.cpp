#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<bitset>
#define mk make_pair
#define fi first
#define nd second
#define pii pair<int,int>
#define pb push_back
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
inline ll read() {ll x = 0; char ch = getchar(), w = 1;while(ch < '0' || ch > '9') {if(ch == '-') w = -1;
ch = getchar();}while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * w;}
void write(ll x) {if(x < 0) putchar('-'), x = -x;if(x > 9) write(x / 10);putchar(x % 10 + '0');}
inline void writeln(ll x) {write(x);puts("");}
const int N = 1e5 + 6;
int n;
ll x[N], t[N];
ll m, k;
int b[N];
int c[N], tmp[N];
void solve() {
	for(; k; k >>= 1) {
		
		if(k & 1) {
			for(int i = 1;  i <= n; ++i) tmp[i] = t[i];
			for(int i = 1; i <= n; ++i) t[i] = tmp[c[i]];
		}
		for(int i = 1; i <= n; ++i) tmp[i] = c[i];
		for(int i = 1; i <= n; ++i) c[i] = tmp[c[i]];
	}
}
int main() {
	n = read();
	for(int i = 1; i <= n; ++i) x[i] = read(), t[i] = x[i] - x[i - 1], c[i] = i;
	m = read(), k = read();
	for(int i = 1; i <= m; ++i) {
		b[i] = read();
		swap(c[b[i]], c[b[i] + 1]);
	}
	solve();
	ll res = 0;
	for(int i = 1; i <= n; ++i) {
		res += t[i];
		writeln(res);
	}
	return 0;
}