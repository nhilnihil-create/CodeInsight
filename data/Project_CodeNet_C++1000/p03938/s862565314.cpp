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
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int A[N], B[N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		A[i] += i * n + 1, B[i] = (n - i - 1) * n + 1;
		int p; cin >> p; p--;
		A[p] += i;
	}
	for (int i = 0; i < n; i++) cout << A[i] << ends;
	cout << endl;
	for (int i = 0; i < n; i++) cout << B[i] << ends;
	cout << endl;


	return 0;
}
