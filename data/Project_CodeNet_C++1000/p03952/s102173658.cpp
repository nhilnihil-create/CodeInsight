// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef unsigned long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 2e5 + 5;

bool M[N];
int A[N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, x; cin >> n >> x;
	if (x + 1 == 2 * n || x == 1) die("No");
	if (n == 2) {
		cout << "Yes" << endl;
		cout << 1 << ends << 2 << ends << 3 << endl;
		return 0;
	}
	if (x != 2) {
		A[n - 1] = 1;
		A[n] = 2 * n - 1;
		A[n + 1] = x;
		A[n + 2] = 2;
		M[2 * n - 1] = M[1] = M[2] = M[x] = true;
	} else {
		A[n - 1] = 2 * n - 1;
		A[n] = 1;
		A[n + 1] = 2;
		A[n + 2] = 3;
		M[2 * n - 1] = M[1] = M[2] = M[3] = true;
	}
	cout << "Yes" << endl;
	int p = 1;
	for (int i = 1; i <= 2 * n - 1; i++) {
		if (A[i]) cout << A[i] << endl;
		else {
			while (M[p]) p++;
			M[p] = true;
			cout << p << endl;
		}
	}

	return 0;
}
