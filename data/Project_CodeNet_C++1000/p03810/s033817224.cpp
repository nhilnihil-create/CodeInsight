#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 100000 + 10;
const int MOD = 1000000007;
const int LOG = 20;
const int INF = 1000000010;
const int delta = 11353;
 
int n, A[N];
bool Solve() {
	
	bool f = 1;
	for(int i = 1; i <= n; i++) if (A[i] != 1) f = 0;
	if (f) return 0;
	int Ev = 0, Od = 0; 
	int id = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i] % 2 == 1) Od++, id = i;
		else Ev++;
	}
 
	if (Ev % 2 == 1) return 1; 
	if (Od > 1) return 0; 
	if (A[id] == 1) return 0; 
	A[id]--;
 
	int g = A[0];
	for (int i = 1; i <= n; i++) g = __gcd(g, A[i]);
	for (int i = 1; i <= n; i++) A[i] /= g;
 
	f = Solve();
	return !f;
}
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	if (Solve()) cout << "First" << endl; 
	else cout << "Second" << endl;
	return 0;
}