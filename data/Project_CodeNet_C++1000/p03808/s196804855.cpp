#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60

int A[100001];
ll dif[100001];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N; cin >> N;
	ll tot = 0LL;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		tot += A[i];
	}
	for (int i = 1; i < N; i++) dif[i] = A[i] - A[i - 1];
	dif[0] = A[0] - A[N - 1];

	if (tot % ((N*(N + 1))/ 2) != 0) cout << "NO" << endl;
	else {
		ll k = tot / (N*(N + 1) / 2);
		bool flag = true;
		for (int i = 0; i < N; i++) {
			dif[i] -= k;
			if (dif[i] > 0) flag = false;
			else {
				if (-dif[i] % N != 0) flag = false;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
 
	return 0;
}