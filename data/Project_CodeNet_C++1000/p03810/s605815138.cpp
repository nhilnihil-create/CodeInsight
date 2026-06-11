#include <bits/stdc++.h>

const int N=1e5+10;

int n,A[N];

void Init() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&A[i]);
}

int gcd(int a,int b) { return !b?a:gcd(b,a%b); }

bool Dfs(int f) {
	int odd=0,fl=1;
	for (int j=1;j<=n;++j)  { 
		if (A[j]&1) odd++; 
		if (A[j]==1) fl=0;
	}
	if (odd>=2 && !((n-odd)&1)) return f^1;
	if (odd>=1 && (n-odd)&1) return f;
	if (!fl) return (n-odd)&1;
	for (int j=1;j<=n;++j) if (A[j]&1) { A[j]--; break; }
	int g=A[1]; for (int j=2;j<=n;++j) g=gcd(g,A[j]);
	for (int j=1;j<=n;++j) A[j]/=g;
	return Dfs(f^1);
}

void Solve() {
	if (Dfs(1)) printf("First\n");
	else printf("Second\n");
}

int main() {
	Init();
	Solve();
	return 0;
}