#include <bits/stdc++.h> 
using namespace std; 
int gi() { 
	int res = 0, w = 1; 
	char ch = getchar(); 
	while (ch != '-' && !isdigit(ch)) ch = getchar(); 
	if (ch == '-') w = -1, ch = getchar(); 
	while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar(); 
	return res * w; 
} 
const int MAX_N = 1e5 + 5; 
int N, a[MAX_N];
void doit() {
	int g = 0;
	for (int i = 1; i <= N; i++) g = __gcd(g, a[i]); 
	for (int i = 1; i <= N; i++) a[i] /= g; 
} 
int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	N = gi(); 
	for (int i = 1; i <= N; i++) a[i] = gi();
	int now = 0; 
	while (1) {
		bool flag = 0; 
		int cnt1 = 0, cnt2 = 0, p = 0; 
		for (int i = 1; i <= N; i++) { 
			if (a[i] & 1) p = i, cnt1++; 
			else cnt2++; 
			if (a[i] == 1) flag = 1; 
		} 
		if (flag) return puts((cnt2 & 1) ^ now ? "First" : "Second") & 0; 
		if (cnt2 & 1) return puts(now ? "Second" : "First") & 0; 
		if (cnt1 > 1 && !(cnt2 & 1)) return puts(now ? "First" : "Second") & 0; 
		a[p]--, doit(), now ^= 1; 
	} 
    return 0; 
} 