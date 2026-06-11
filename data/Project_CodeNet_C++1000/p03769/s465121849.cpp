#include <bits/stdc++.h> 
using namespace std; 
long long N; 
int p[200], q[200], cnt = 1;
void solve(long long n) {
	if (!n) return;
   	if (~n & 1) 
		q[++q[0]] = cnt++, solve(n - 1); 
   	else
   		p[++p[0]] = cnt++, solve(n >> 1); 
} 
int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	cin >> N; 
	solve(N); 
	printf("%d\n", cnt + 100 - 1);
	for (int i = 1; i <= q[0]; i++) printf("%d ", cnt - q[i]); 
	for (int i = p[0]; i; i--) printf("%d ", cnt - p[i]); 
	for (int i = 1; i <= 100; i++) printf("%d ", i); 
	putchar('\n'); 
    return 0; 
} 