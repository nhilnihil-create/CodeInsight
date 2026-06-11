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

ll cnt[100010];
int main()
{
	ll N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cnt[a] += b;
	}
	int ans = 0;
	while (K > 0) {
		K -= cnt[ans++];
	}
	cout << ans - 1 << endl;
}