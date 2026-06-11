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
int N, C, K, a[MAX_N]; 
int ans = 1; 

int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	N = gi(), C = gi(), K = gi(); 
	for (int i = 1; i <= N; i++) a[i] = gi(); 
	sort(&a[1], &a[N + 1]); 
	for (int i = 1, lst = 1; i <= N; i++) 
		if (i - lst + 1 > C || a[lst] + K < a[i])
			lst = i, ans++;
	printf("%d\n", ans); 
    return 0; 
} 