#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_ ; ++i)
#define drep(i, a, b) for(register int i = (a), i##_end_ = (b); i >= i##_end_ ; --i)
#define clear(a, b) memset((a), (b), sizeof(a))
typedef long long LL;
int read() {
	int x = 0, flag = 1;
	char ch = getchar();
	while(!isdigit(ch)) {
		if(ch == '-') flag = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch - 0x30);
		ch = getchar();
	}
	return flag * x;
}

#define Maxn 100009
int n, a[Maxn];
int pos[Maxn];
LL dis[Maxn];
int m, base[Maxn], r[Maxn], tmp[Maxn];
LL k;
void Permutation_FPower(LL b) {
	rep(i, 1, n) r[i] = i;
	rep(i, 1, n) base[i] = pos[i];
	while(b) {
		if(b & 1) {
			rep(i, 1, n) tmp[i] = r[base[i]];
			rep(i, 1, n) r[i] = tmp[i];
		}
		rep(i, 1, n) tmp[i] = base[base[i]];
		rep(i, 1, n) base[i] = tmp[i];
		b >>= 1;
	}
}
int main() {
#ifdef Qrsikno
	freopen("h.in","r",stdin);
	freopen("h.out","w",stdout);
#endif
	n = read();
	rep(i, 1, n) a[i] = read(), dis[i] = a[i] - a[i - 1], pos[i] = i;
	scanf("%d %lld\n", &m, &k);
	rep(i, 1, m) {
		int x = read();	
		swap(pos[x], pos[x + 1]);
	}
	Permutation_FPower(k);
	rep(i, 1, n) tmp[i] = dis[r[i]];
	rep(i, 1, n) dis[i] = tmp[i];
	LL now_Position = 0;
	rep(i, 1, n) {
		now_Position += dis[i];
		printf("%.1lf\n", now_Position * 1.0);
	}
	return 0;
}
