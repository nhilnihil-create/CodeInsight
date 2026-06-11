#include <iostream>
#include <cstdio>
using namespace std;

int q, a, b, c, d, num, x[100005], y[100005];
string s, t;
int main() {
	int i;
	cin >> s >> t >> q;
	for(i=0; s[i]; i++) x[i+1] = x[i] + s[i]-'A' + 1;
	for(i=0; t[i]; i++) y[i+1] = y[i] + t[i]-'A' + 1;
	while(q--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		num = (x[b] - x[a-1] - y[d] + y[c-1] + 300000) % 3;
		puts(num ? "NO" : "YES");
	}
	return 0;
}