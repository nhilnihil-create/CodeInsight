#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	ll N, M;
	cin >> N >> M;
	if (abs(N - M) > 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	for (int i = 1; i <= N; i++) ans = (ans * i) % mod;
	for (int i = 1; i <= M; i++) ans = (ans * i) % mod;
	if (N - M == 0) cout << (ans * 2) % mod << endl;
	else cout << ans % mod << endl;
}