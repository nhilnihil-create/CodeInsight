#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define nd second
#define pii pair<int,int>
#define sqr(x) ((x)*(x))
using namespace std; 
typedef long long ll;
inline ll read() {ll x = 0; char ch = getchar(), w = 1;while(ch < '0' || ch > '9') {if(ch == '-') w = -1;
ch = getchar();}while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * w;}
void write(ll x) {if(x < 0) putchar('-'), x = -x;if(x > 9) write(x / 10);putchar(x % 10 + '0');}
inline void writeln(ll x) {write(x);puts("");}
const int N = 2000000;
int n;
struct T {
	int i;
	ll val;
}a[N];
bool cmp(T _x, T _y) {
	if(_x.val != _y.val) return _x.val < _y.val;
	return _x.i < _y.i;
}
ll ans[N];
int main() {
	n = read();
	for(int i = 1; i <= n; ++i) a[i].val = read(), a[i].i = i;
	sort(a + 1, a + 1 + n, cmp);
	int id = n + 1;
	for(int i = n; i;--i) {
		int j = i;
		id = min(id, a[i].i);
		while(j && a[j - 1].val == a[i].val) id = min(id, a[j - 1].i),--j;
		ans[id] += (a[j].val - a[j - 1].val) * (n - j + 1);
		i = j;
	}
	for(int i = 1;  i<= n; ++i)
		writeln(ans[i]);
	return 0;
}