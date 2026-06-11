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
const int MAX_N = 3e5 + 5; 
int N, a[MAX_N]; 

int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	N = gi(); 
	for (int i = 1; i <= 3 * N; i++) a[i] = gi(); 
	sort(&a[1], &a[3 * N + 1], greater<int>()); 
	long long ans = 0; 
	for (int i = 1; i <= N; i++) ans += a[i << 1];
	printf("%lld\n", ans); 
    return 0; 
} 