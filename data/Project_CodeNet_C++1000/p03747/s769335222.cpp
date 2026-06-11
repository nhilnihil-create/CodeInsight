#include "bits/stdc++.h"
#include<assert.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define MRE assert(0);
const int inf = 1e17;
const int mod = 924844033;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int N, L, T;
int x[100006], w[100006];
int FP[100006],FX[100006];

int cntcross(int S) {
	int res = 0;
	rep(i, N) {
		if (w[S] != w[i]) {
			int dis;
			if (w[S] == 1)dis = (x[i] - x[S] + L) % L;
			else dis = (L + x[S] - x[i]) % L;
			if (dis <= 2 * T)res += (2 * T - dis) / L + 1;
		}
	}
	return res;
}

signed main() {
	cin >> N >> L >> T;
	rep(i, N) cin >> x[i] >> w[i];

	vector<P>V1;
	rep(i, N) {
		if (w[i] == 1) {
			FP[i] = (x[i] + T) % L;
		}
		else {
			FP[i] = (x[i] + L - T%L) % L;
		}
		V1.push_back(P(FP[i], i));
	}
	sort(V1.begin(), V1.end());
	if (N == 1) {
		cout << FP[0] << endl;
		return 0;
	}
	sort(FP, FP + N);
	int X0, P0 = FP[0], I1 = V1[0].second;
	if (w[I1] == 1)X0 = (I1 + cntcross(I1)) % N;
	else X0 = (N - cntcross(I1)%N + I1) % N;

	rep(i, N) {
		if (FP[i] == P0) {
			rep(j, N) {
				FX[(i + j) % N] = (X0 + j) % N;
			}
			break;
		}
	}
	vector<P>V;
	rep(i, N) {
		V.push_back(P(FX[i], FP[i]));
	}
	sort(V.begin(), V.end());
	rep(i, N)cout << V[i].second << endl;
}
