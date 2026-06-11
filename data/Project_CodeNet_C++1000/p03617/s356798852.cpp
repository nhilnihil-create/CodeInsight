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
	int A[5];
	int N;
	int n = 4;
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> N;
	int sum = A[0];
	for (int i = 1; i < n - 1; i++) {
		sum = min(sum * 2, A[i]);
	}
	ll ans = 0;
	ans += (ll)N / 2 * min(sum * 2, A[n - 1]);
	ans += (ll)(N % 2) * sum;
	cout << ans << endl;
}
