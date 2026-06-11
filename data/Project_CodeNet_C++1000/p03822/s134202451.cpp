#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

vector<int> E[100001];
int memo[100001];
int sagasu(int A) {
	if (memo[A]) return memo[A];
	vector<int> kari;
	for (int i : E[A]) kari.pb(sagasu(i));
	sort(kari.begin(), kari.end());
	reverse(kari.begin(), kari.end());
	int ret = 1;
	rep(i, kari.size()) {
		ret = max(ret, i + kari[i] + 1);
	}
	return memo[A] = ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		int a;
		cin >> a;
		E[a].pb(i);
	}

	rep1(i, N) cesp(sagasu(i));

	co(sagasu(1) - 1);


	Would you please return 0;
}