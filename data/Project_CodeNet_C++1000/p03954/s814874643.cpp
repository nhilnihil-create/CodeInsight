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

int n, P[N];
bool A[N];

bool Top(int x) {
	for (int i = 0; i <= 2 * n; i++) A[i] = (P[i] >= x);
	if (A[n] == A[n - 1] || A[n] == A[n + 1]) return A[n];
	int l = n, r = n;
	while (A[l - 1] == !A[l]) l--;
	while (A[r + 1] == !A[r]) r++;
	if ((n - l) < (r - n)) return A[l];
	else return A[r];
}

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i < 2 * n; i++) cin >> P[i];
	P[0] = P[1], P[2 * n] = P[2 * n - 1];
	
	int dw = 0, up = 2 * n;
	while (up - dw > 1) {
		int md = (dw + up) >> 1;
		if (Top(md)) dw = md;
		else up = md;
	}
	cout << dw << endl;

	return 0;
}
