#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
using namespace std; 
inline int gi() { 
    register int data = 0, w = 1;
    register char ch = 0;
    while (!isdigit(ch) && ch != '-') ch = getchar(); 
    if (ch == '-') w = -1, ch = getchar(); 
    while (isdigit(ch)) data = 10 * data + ch - '0', ch = getchar(); 
    return w * data; 
} 
const int MAX_N = 1e5 + 5; 
int N, L, a[MAX_N], f[17][MAX_N]; 

int main () { 
	N = gi(); for (int i = 1; i <= N; i++) a[i] = gi();
	L = gi(); 
	for (int i = 1; i <= N; i++) f[0][i] = upper_bound(&a[i + 1], &a[N + 1], a[i] + L) - a - 1; 
	for (int i = 1; i < 17; i++) 
		for (int j = 1; j <= N; j++) f[i][j] = f[i - 1][f[i - 1][j]]; 
	int Q = gi(); 
	while (Q--) { 
		int l = gi(), r = gi(); 
		if (l > r) swap(l, r); 
		int ans = 0; 
		for (int i = 16; ~i; i--) if (f[i][l] < r) l = f[i][l], ans |= (1 << i); 
		printf("%d\n", ans + 1); 
	} 
    return 0; 
} 