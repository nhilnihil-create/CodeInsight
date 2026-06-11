#include <cstdio>
#include <map>
using namespace std;

int fa1[200010], fa2[200010];

int find_root1(int a) {
	return fa1[a] && fa1[a] != a ? fa1[a] = find_root1(fa1[a]) : a;
}

int find_root2(int a) {
	return fa2[a] && fa2[a] != a ? fa2[a] = find_root2(fa2[a]) : a;
}

void merge1(int a, int b) {
	int f1 = find_root1(a);
	int f2 = find_root1(b);
	if (f1 != f2) fa1[f1] = f2;
}

void merge2(int a, int b) {
	int f1 = find_root2(a);
	int f2 = find_root2(b);
	if (f1 != f2) fa2[f1] = f2;
}

map <long long, int> mp;

int main() {
	int n, k, l;
	scanf("%d%d%d", &n, &k, &l);
	while (k--) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge1(a, b);
	}
	while (l--) {
		int a, b;
		scanf("%d%d", &a, &b);
		merge2(a, b);
	}
	for (int i = 1; i <= n; ++i) {
		fa1[i] = find_root1(i);
		fa2[i] = find_root2(i);
		++mp[fa1[i] * 500000ll + fa2[i]];
	}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", mp[fa1[i] * 500000ll + fa2[i]], " \n"[i == n]);
	return 0;
}
