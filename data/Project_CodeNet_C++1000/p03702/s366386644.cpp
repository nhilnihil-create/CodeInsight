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

ll hp[100001];
int N;
int AA, PA; // All Attack     : B
			// Private Attack : A-B

void input() {
	int A, B;
	cin >> N >> A >> B;
	AA = B;
	PA = A - B;

	for (int i = 0; i < N; i++) cin >> hp[i];
}

// k回の爆発ですべて倒せるかどうか
bool isWin(ll k) {
	vector<ll> restMonster;
	for (int i = 0; i < N; i++) {
		if (hp[i] > AA*k) restMonster.push_back(hp[i] - AA * k);
	}
	ll tot = 0;
	for (int i = 0; i < restMonster.size(); i++) {
		if (restMonster[i] % PA == 0) tot += restMonster[i] / PA;
		else tot += restMonster[i] / PA + 1;
	}
	return (tot <= k);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	input();

	// 2分探索
	// 解は left < 解 <= right
	ll left = 0;
	ll right = 1000000000;
	while (right != left + 1) {
		ll mid = (left + right) / 2;
		if (isWin(mid)) right = mid;
		else left = mid;
	}

	cout << right << endl;

	return 0;
}