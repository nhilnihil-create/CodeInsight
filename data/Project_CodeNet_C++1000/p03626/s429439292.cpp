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
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	string S[2];
	cin >> S[0] >> S[1];
	vector<bool> V;
	for (int i = 0; i < N; i++) {
		if (i < N - 1 && S[0][i] == S[0][i + 1]) {
			V.push_back(false);
			i++;
		}
		else V.push_back(true);
	}
	bool befo = V[0]; // 前が縦
	ll ans;
	if (befo) ans = 3;
	else ans = 6;
	for (int i = 1; i < V.size(); i++) {
		if (befo) {
			ans *= 2;
			ans %= MOD;
			befo = V[i];
		}
		else {
			if (V[i]) befo = V[i];
			else {
				ans *= 3;
				ans %= MOD;
				befo = V[i];
			}
		}
	}
	cout << ans << endl;
	

	return 0;
}