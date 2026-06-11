/* */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())
#define dbg_al(s, x) for(auto e:x)s+=to_string(e)+" "
#define dbg_rt(x) string s="[ ";dbg_al(s,x);s+="]";return s;
#define dbg_fd1 template<typename T>string to_string
#define dbg_fd2 template<typename U, typename V>string to_string
#define dbg_d1(c) dbg_fd1(c<T>);
#define dbg_d2(c) dbg_fd2(c<U, V>);
#define dbg_f1(c) dbg_fd1(c<T> v){dbg_rt(v);}
#define dbg_f2(c) dbg_fd2(c<U, V> v){dbg_rt(v);}
string to_string (char s) { return "\'"+string(1, s)+"\'"; }
string to_string (string s) { return "\"" + s + "\""; }
dbg_d1(vector) dbg_d1(set) dbg_d2(map)
dbg_fd2(pair<U, V> p) { return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
dbg_f1(vector) dbg_f1(set) dbg_f2(map)
/* ==================== */ 

int solve (int h, int w) {
	if (h % 3 == 0 || w % 3 == 0) return 0;
	int a, b, c, x, y;
	if (h % 3 == 1) {
		a = (h / 3) * w;
		x = h - h / 3;
	}
	else {
		a = (h / 3 + 1) * w;
		x = h - (h / 3 + 1);
	}
	y = w;
	if (x > y) swap(x, y);
	if (x % 2 == 0) {
		b = (x / 2) * y;
		c = (x / 2) * y;
	}
	else {
		b = x * (y / 2);
		c = x * ((y - 1) / 2 + 1);
	}
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	return c - a;
}

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	printf("%d\n", min(solve(h, w), solve(w, h)));
}
