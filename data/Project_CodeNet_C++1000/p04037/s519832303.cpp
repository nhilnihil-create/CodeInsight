#include <bits/stdc++.h>
using namespace std;
#define M 100010
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
int a[M];
int main() {
	int n = read();
	rep(i, 1, n) {
		a[i] = read();
	} sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1); int ans = 0;
	rep(i, 1, n) if(i + 1 > a[i + 1]){
		for(int j = i + 1; a[j] == i; j ++) ans ^= 1;
		ans |= (a[i] - i) & 1;
		puts(ans?"First":"Second");
		return 0;
	}
}