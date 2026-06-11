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

int N, K;
int A[100010], B[100010];
ll ret;

int main() {
	cin >> N >> K;
	rep(i, N) {
		cin >> A[i] >> B[i];
	}

	for (int i = 29; i >= 0; --i) {
		if ((K >> i) & 1) {
			ll t = 0;
			rep(j, N) if (A[j] < (1 << i)) {
				t += B[j];
			}
			ret = max(ret, t);
			K ^= (1 << i);

			rep(j, N) if ((A[j] >> i) & 1) {
				A[j] ^= (1 << i);
			}
		}
	}

	ll t = 0;
	rep(j, N) {
		if (A[j] == 0) {
			t += B[j];
		}
	}
	ret = max(ret, t);

	cout << ret << endl;

	return 0;
}