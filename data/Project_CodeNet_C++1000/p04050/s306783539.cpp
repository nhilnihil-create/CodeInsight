#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, x, y) for(int i = (x); i <= (y); i ++)
inline int read() {
	char ch = getchar(); int x = 0, f = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	} while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	} return x * f;
}
vector<int> ev;
int a[100010];
int main() {
	int n = read(), m = read();
	rep(i, 1, m) a[i] = read();
	rep(i, 1, m) if(a[i] & 1) ev.pb(i);
	if(ev.size() > 2) {
		return puts("Impossible"), 0;
	} if(m == 1) {
		if(a[1] == 1) {
			printf("1\n1\n1\n");
			return 0;
		} printf("%d\n", a[1]);
		puts("2"); printf("%d 1\n", a[1] - 1);
		return 0;
	} if(ev.size() >= 1) swap(a[1], a[ev[0]]);
	if(ev.size() >= 2) swap(a[m], a[ev[1]]);
	rep(i, 1, m) printf("%d ", a[i]); puts("");
	if(a[m] == 1) m --; else a[m] --;
	printf("%d\n", m); a[1] ++;
	rep(i, 1, m) printf("%d ", a[i]); 
	return 0;
}