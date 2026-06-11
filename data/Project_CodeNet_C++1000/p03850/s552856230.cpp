#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
vector<ll> A;
vector<string> OP;
ll memo[100000][3];
bool visited[100000][3];
ll f(int p, int q) {
	if (q < 0 || q >= 3) return -(1LL << 60);
	if (p == N) return 0;
	if (visited[p][q]) return memo[p][q];
	visited[p][q] = true;
	int qq = q;
	if (OP[p] == "-") ++qq;
	return memo[p][q] = max(f(p + 1, qq), f(p + 1, qq-1)) + (qq % 2 == 0 ? A[p] : -A[p]);
}
int main() {
	cin >> N;
	A.resize(N);
	OP.resize(N);
	OP[0] = "+";
	for (int i = 0; i < N; ++i) {
		if (i) cin >> OP[i];
		cin >> A[i];
	}
	cout << f(0, 0) << endl;
}
