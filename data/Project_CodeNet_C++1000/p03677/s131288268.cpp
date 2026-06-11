#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 100;

int N, M, Nr[MAX_N];
ll Sum[MAX_N * 2], Slope[MAX_N * 2], SlopeC[MAX_N * 2];
ll Ans[MAX_N];
int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) scanf("%d", &Nr[i]);
	for(int i=0; i<N-1; i++) {
		int l = Nr[i], r = Nr[i+1];
		if(r < l) r += M;
		Slope[r]++; Slope[l]--; SlopeC[l] += r-l;
		Sum[l+M] += r-l; Sum[r] -= r-l;
	}
	ll plus = 0;
	for(int i=2*M; i>=1; i--) {
		Sum[i] += Sum[i+1];
		Slope[i] += Slope[i+1];
		plus += Slope[i];
		plus -= SlopeC[i];
		Ans[(i-1)%M] += Sum[i] + plus;
	}
	ll ans = LINF;
	for(int i=0; i<M; i++) ans = min(ans, Ans[i]);
	printf("%lld\n", ans);
	return 0;
}
