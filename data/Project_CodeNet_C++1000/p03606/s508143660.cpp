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
	int N;
	ll ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		ans += r - l + 1;
	}
	cout << ans << endl;
}
