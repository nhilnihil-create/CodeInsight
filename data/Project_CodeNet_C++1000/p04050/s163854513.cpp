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

int N, M;
int A[110];

int main() {
	cin >> N >> M;
	int co = 0;
	vi ve, vo;

	rep(i, M) {
		cin >> A[i];
		if (A[i] & 1) {
			++co;
			vo.pb(A[i]);
		} else {
			ve.pb(A[i]);
		}
	}

	if (co > 2) {
		puts("Impossible");
	} else {
		if (M == 1) {
			printf("%d\n", A[0]);
			if (N == 1) {
				puts("1");
				puts("1");
			} else {
				printf("2\n");
				printf("%d 1\n", A[0]-1);
			}
			return 0;
		}

		vi vec;
		int p = 0;
		if (p < vo.size()) {
			vec.pb(vo[p++]);
		}
		for (int x : ve) {
			vec.pb(x);
		}
		if (p < vo.size()) {
			vec.pb(vo[p]);
		}

		rep(i, M) {
			printf("%d%c", vec[i], i == M-1 ? '\n' : ' ');
		}

		--vec[0];
		++vec.back();

		vi ans;
		for (int x : vec) {
			if (x > 0) ans.pb(x);
		}
		printf("%d\n", ans.size());

		rep(i, ans.size()) {
			printf("%d%c", ans[i], i == (int)ans.size()-1 ? '\n' : ' ');
		}
	}

	return 0;
}