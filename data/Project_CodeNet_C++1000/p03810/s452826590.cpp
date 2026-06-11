#include<bits/stdc++.h>
#define For(i, j, k) for(int i = j; i <= k; ++i)
#define Forr(i, j, k) for(int i = j; i >= k; --i)
using namespace std;

inline int read() {
	int x = 0, p = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') p = -1; c = getchar(); }
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x *= p;
}

const int N = 1e5 + 10;
int n, A[N], GCD;

inline bool dfs() {
	int cnt1 = 0, cnt2 = 0, flag = 0;
	For(i, 1, n) {
		if(A[i] == 1) flag = 1;
		if(A[i] & 1) ++ cnt1;
		else ++ cnt2;
	}

	if(cnt2 & 1) return 1;
	else if(cnt1 == 1 && flag == 1 || cnt1 > 1) return 0;
	else {
		int GCD = 0;
		For(i, 1, n) {
			if(A[i] & 1) -- A[i];
			GCD = __gcd(GCD, A[i]);
		}	
		For(i, 1, n) A[i] /= GCD;
		return dfs() ^ 1;
	}
}

int main() {
	n = read();
	For(i, 1, n) A[i] = read();

	if(dfs()) puts("First");
	else puts("Second");

	return 0;
}