#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int N, A, B;
int h[1000010];
// index が条件を満たすかどうか
bool isOK(ll n) {
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		sum += max(0ll,(h[i] - B * n + A - B - 1)) / (A - B);
	}
	if (sum <= n) return true;
	else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search() {
	ll ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
	ll ok = mod; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* ok と ng のどちらが大きいかわからないことを考慮 */
	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (isOK(mid)) ok = mid;
		else ng = mid;
	}
	return ok;
}

int main()
{

	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}
	cout << binary_search() << endl;
}