#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { for(;b;swap(a,b))a%=b; return a; }

const int MAXN = 100055;

int A[MAXN];

int N, T;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];

	for(int ev, od;;) {
		ev = od = 0;
		for(int i = 1; i <= N; i++) {
			if((A[i]&1) && 2 < A[i]) od++;
			if(!(A[i]&1)) ev++;
		}
		if(ev&1) break;
		if(1 != od) {
			T = !T;
			break;
		}
		for(int i = 1; i <= N; i++) if((A[i]&1) && 2 < A[i]) {
			A[i]--;
			break;
		}
		int G = A[1];
		for(int i = 2; i <= N; i++) G = gcd(G, A[i]);
		for(int i = 1; i <= N; i++) A[i] /= G;
		T = !T;
	}

	puts(T ? "Second" : "First");
	return 0;
}