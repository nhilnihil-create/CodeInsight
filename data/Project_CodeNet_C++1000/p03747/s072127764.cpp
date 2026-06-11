#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 100010;

int N, L, T;
int x[MN], w[MN];

int main() {
	cin >> N >> L >> T;

	vi vec(N);

	int dec = 0;

	rep(i, N) {
		cin >> x[i] >> w[i];
		int p = x[i] + (w[i] == 1 ? T : -T);
		p %= L;
		if (p < 0) p += L;
		vec[i] = p;

		if (w[i] == 1) {
			if (T > (L-x[i])) {
				dec += ((T - 1 - (L - x[i])) / L + 1);
			}
		} else {
			if (T > x[i]) {
				dec -= ((T - 1 - x[i]) / L + 1);
			}
		}
		dec %= N;
		if (dec < 0) dec += N;		
	}

	sort(ALL(vec));

	rep(i, N) {
		printf("%d\n", vec[dec]);
		++dec;
		if (dec == N) dec = 0;		
	}
	return 0;
}