#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
inline int Get() {
	char ch;
	while ((ch = getchar()) < '0' || ch > '9');
	int Num = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		Num = (Num << 3) + (Num << 1) + ch - '0';
	return Num;
}
int n, a[N];
inline bool cmp(const int &a, const int &b) {
	return a > b;
}
int main() {
	n = Get();
	for (int i = 1; i <= n; ++i) a[i] = Get();
	std :: sort(a + 1, a + n + 1, cmp);
	
	int id = 0;
	while (id + 1 < n && id + 1 < a[id + 2]) ++id;
	
	int flagA = (a[id + 1] - id) & 1;
	int flagB = 1, rev = id;
	while (id + 1 < n && rev < a[id + 2]) ++id, flagB ^= 1;
	
	int flag = !(flagA & flagB);
	puts(flag ? "First" : "Second");
}