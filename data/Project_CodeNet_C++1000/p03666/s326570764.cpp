#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define putchar putchar_unlocked
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	N--;
	bool OK = false;
	rep(i, N + 1) {
		ll X = (2 * i - N) * C - (D - C) * (N - i);
		ll Y = (2 * i - N) * C + (D - C) * i;
		if (X <= B - A && B - A <= Y) OK = true;
	}
	if (OK) co("YES");
	else co("NO");

	Would you please return 0;
}