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

int A[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll ans = A[0] / 2;
	A[0] %= 2;
	for (int i = 1; i < N; i++) {
		ans += min(A[i - 1], A[i]);
		A[i] -= min(A[i - 1], A[i]);
		ans += A[i] / 2;
		A[i] %= 2;
	}
	cout << ans << endl;
}