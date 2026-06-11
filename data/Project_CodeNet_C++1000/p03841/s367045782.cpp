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

int N;
bool us[300010];
int x[510];
pii e[510];
int pos[510][510];
int ans[300010];

int main() {
	cin >> N;

	rep(i, N) {
		cin >> x[i];
		--x[i];
		us[x[i]] = 1;
		e[i] = mp(x[i], i);
		pos[i][i] = x[i];
	}

	sort(e, e + N);

	int now = 0;

	rep(i, N) {
		int p = e[i].se;
		rep(j, p) {
			while (us[now]) {
				++now;
				if (now >= e[i].fi) {
					puts("No");
					return 0;
				}
			}
			us[now] = 1;
			pos[p][j] = now;
		}
	}

	reverse(e, e + N);

	now = N * N - 1;
	rep(i, N) {
		int p = e[i].se;
		for (int j = N-1; j > p; --j) {
			while (us[now]) {
				--now;
				if (now <= e[i].fi) {
					puts("No");
					return 0;
				}
			}
			us[now] = 1;
			pos[p][j] = now;
		}
	}

	rep(i, N) {
		rep(j, N) {
			ans[pos[i][j]] = i;
		}
	}

	puts("Yes");
	rep(i, N*N) {
		printf("%d%c", ans[i] + 1, i == N*N-1 ? '\n' : ' ');
	}

	return 0;
}