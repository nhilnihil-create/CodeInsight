#include <bits/stdc++.h>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define revv(V) reverse(allv(V))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

int A[MAXN], B[MAXN];
pii C[MAXN];

int Ans[MAXN];

int N, L, T, X, F;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> L >> T;
	for(int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
	}

	X = A[1];
	for(int i = 1; i <= N; i++)
		A[i] = ((A[i] - X) % L + L) % L;

	if(2 == B[1]) {
		F = 1;
		for(int i = 1; i <= N; i++) {
			B[i] = 3-B[i];
			A[i] = (L-A[i]) % L;
		}
	}

	for(int i = 1; i <= N; i++) {
		if(1 == B[i]) {
			ll x = ll(A[i]) + T;
			x %= L;
			if(x) C[i] = pii(x, 1);
			else C[i] = pii(L, 1);
		} else {
			ll x = ll(A[i]) - T;
			x %= L;
			x = (x + L) % L;
			C[i] = pii(x, 2);
		}
	}
	sort(C+1, C+N+1);

	//for(int i = 1; i <= N; i++)
    //  printf("%d : %d %d : %d %d\n", i, A[i], B[i], C[i].first, C[i].second);

	{
		ll sum = 0;
		for(int i = 2; i <= N; i++) {
			if(1 == B[i] || 2*T <= A[i]) continue;
			sum += (2*T - A[i] - 1) / L + 1;
		}
		sum %= N;

		int idx = (1+sum) % N;
		if(!idx) idx = N;

		if(F && 1 != idx) {
            idx = N+2-idx;
		}

		//printf("sum=%lld, idx=%d\n", sum, idx);

		pii p = pii((A[1]+T)%L, 1);
		if(!p.first) p.first = L;
		int i = 1;
		for(; C[i] != p; i++);

		for(int j = 0; j < N; j++) {
			int x = (!F) ? ((idx+j) % N) : ((idx-j+N) % N);
			if(!x) x = N;

			int y = (i+j) % N;
			if(!y) y = N;

			//printf("x=%d, y=%d\n", x, y);

			Ans[x] = C[y].first;
		}
	}

	if(F) {
		for(int i = 1; i <= N; i++)
			Ans[i] = (L-Ans[i]) % L;
	}
	for(int i = 1; i <= N; i++)
		Ans[i] = (Ans[i] + X) % L;

	for(int i = 1; i <= N; i++)
		printf("%d\n", Ans[i] % L);
	return 0;
}