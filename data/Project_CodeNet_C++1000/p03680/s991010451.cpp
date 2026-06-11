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
const int INF = 1e9;
const ll MOD = 924844033;
 
////////////////////////////////////////////////////////////////////
 
const int N = 1e5 + 5;

int A[N], H[N];

void DFS(int v, int h = 1) {
	H[v] = h;
	if (!H[A[v]]) DFS(A[v], h + 1);
}

int main() {
 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i], A[i]--;
	DFS(0);
	cout << H[1] - 1 << endl;

	return 0;
}
