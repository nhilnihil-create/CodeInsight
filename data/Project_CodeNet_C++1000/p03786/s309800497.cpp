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
LL s[MAX_N]; 
bool check(int mid) { 
	LL now = s[mid]; 
	for (int i = mid + 1; i <= N; i++) 
		if (1ll * a[i] <= now * 2) now += a[i]; 
		else return 0;
	return 1; 
} 
int main () { 
#ifndef ONLINE_JUDGE 
    freopen("cpp.in", "r", stdin); 
#endif 
	N = gi(); 
	for (int i = 1; i <= N; i++) a[i] = gi(); 
	sort(&a[1], &a[N + 1]); 
	for (int i = 1; i <= N; i++) s[i] = s[i - 1] + a[i]; 
	int l = 1, r = N, ans = N; 
	while (l <= r) { 
		int mid = (l + r) >> 1; 
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1; 
	} 
	printf("%d\n", N - ans + 1); 
    return 0; 
} 