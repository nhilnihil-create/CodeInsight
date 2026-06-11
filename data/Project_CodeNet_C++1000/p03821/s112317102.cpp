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

ll A[100010], B[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	ll ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		A[i] += ans;
		if (A[i] % B[i] != 0) ans += B[i] - (A[i] % B[i]);
	}
	cout << ans << endl;
}
