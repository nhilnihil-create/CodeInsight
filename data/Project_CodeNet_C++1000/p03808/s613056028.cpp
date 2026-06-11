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
typedef long long LL;
const int MAX_N = 1e5 + 5; 
int N, a[MAX_N];
LL sum, per, n; 

int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	N = gi(); per = 1ll * N * (N + 1) / 2; 
	for (int i = 1; i <= N; i++) a[i] = gi(), sum += a[i]; 
	if (sum % per) return puts("NO") & 0; 
	n = sum / per; 
	for (int i = 1; i <= N; i++) { 
		int m = a[i] - a[i % N + 1]; 
		LL t = n + m; 
		if (t % N || t / N < 0 || t / N > n) return puts("NO") & 0; 
	} 
	puts("YES"); 
    return 0; 
} 