#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
using namespace std; 
inline int gi() {
    register int data = 0, w = 1; 
    register char ch = 0; 
    while (!isdigit(ch) && ch != '-') ch = getchar(); 
    if (ch == '-') w = -1, ch = getchar(); 
    while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar(); 
    return w * data; 
} 
const int MAX_N = 3e5 + 5; 
int N, M; 
pair<int, int> p[MAX_N]; 
int ls[MAX_N << 5], rs[MAX_N << 5], sum[MAX_N << 5]; 
int rt[MAX_N], tot; 
void modify(int &o, int p, int l, int r, int pos) { 
	o = ++tot; 
	ls[o] = ls[p], rs[o] = rs[p], sum[o] = sum[p] + 1; 
	if (l == r) return ; 
	int mid = (l + r) >> 1; 
	if (pos <= mid) modify(ls[o], ls[p], l, mid, pos); 
	else modify(rs[o], rs[p], mid + 1, r, pos); 
} 
int query(int u, int v, int l, int r, int ql, int qr) { 
	if (ql <= l && r <= qr) return sum[v] - sum[u]; 
	int mid = (l + r) >> 1, res = 0; 
	if (ql <= mid) res += query(ls[u], ls[v], l, mid, ql, qr); 
	if (qr > mid) res += query(rs[u], rs[v], mid + 1, r, ql, qr); 
	return res; 
} 

int main () { 
	N = gi(), M = gi(); 
	for (int i = 1; i <= N; i++)
		p[i].first = gi(), p[i].second = gi(); 
	sort(&p[1], &p[N + 1]); 
	for (int i = 1, j = 1; i <= M; i++) { 
		rt[i] = rt[i - 1]; 
		while (p[j].first == i && j <= N) modify(rt[i], rt[i], 1, M, p[j].second), ++j; 
	} 
	for (int d = 1; d <= M; d++) { 
		int ans = 0; 
		for (int i = d, pre = 0; i <= M; i += d) 
			ans += query(rt[pre], rt[i], 1, M, i, M), pre = i; 
		printf("%d\n", ans); 
	} 
    return 0; 
} 