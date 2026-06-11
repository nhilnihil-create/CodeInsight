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
int N, L, T; 
int x[MAX_N], dir[MAX_N]; 
long long sum; 
int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin);
	freopen("cpp.out", "w", stdout); 
#endif 
	N = gi(), L = gi(), T = gi(); 
	for (int i = 1; i <= N; i++) x[i] = gi(), dir[i] = gi(); 
	for (int i = 1; i <= N; i++) { 
		if (dir[i] == 1) { 
			int t = L - x[i]; 
			if (T >= t) sum += (T - t) / L + 1; 
		} else { 
			int t = x[i]; 
			if (T > t) sum -= (T - t - 1) / L + 1; 
		} 
		if (dir[i] == 1) x[i] = (x[i] + T) % L; 
		else x[i] = (x[i] - T % L + L) % L; 
	} 
	sort(&x[1], &x[N + 1]); 
	sum = (sum % N + N) % N; 
	for (int i = sum + 1; i <= N; i++) printf("%d\n", x[i]); 
	for (int i = 1; i <= sum; i++) printf("%d\n", x[i]); 
    return 0; 
} 