#include<map>
#include<cstdio>
#include<iostream>
#define nc getchar
#define mp make_pair
using namespace std;
inline void read(int &x) {
	char b = nc(); x = 0;
	for (; !isdigit(b); b = nc());
	for (; isdigit(b); b = nc()) x = x * 10 + b - '0';
}
const int N = 200005;
int n, m1, m2;
struct UFS{
	int fa[N], rk[N];
	inline void init() {
		for (int i = 1; i <= n; ++i) fa[i] = i, rk[i] = 0;
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	inline void merge(int a, int b) {
		if ((a=find(a)) != (b=find(b))) {
			if (rk[a] < rk[b]) swap(a, b);
			fa[b] = a; rk[a] += rk[a] == rk[b];
		}
	}
} s1, s2;
map < pair < int , int > , int > cnt;
int main() {
	read(n); read(m1); read(m2);
	s1.init(); s2.init();
	for (int i = 0, u, v; i < m1; ++i)
		read(u), read(v), s1.merge(u, v);
	for (int i = 0, u, v; i < m2; ++i)
		read(u), read(v), s2.merge(u, v);
	for (int i = 1; i <= n; ++i)
		++cnt[mp(s1.find(i), s2.find(i))];
	for (int i = 1; i <= n; ++i)
		printf("%d ", cnt[mp(s1.find(i), s2.find(i))]);
	return 0;
}
