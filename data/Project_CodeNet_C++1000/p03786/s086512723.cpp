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

ll A[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int ans = N;
	int cnt = 1;
	ll sum = A[0];
	for (int i = 1; i < N; i++) {
		if (sum * 2 >= A[i]) {
			cnt++;
		}
		else {
			ans -= cnt;
			cnt = 1;
		}
		sum += A[i];
	}
	cout << ans << endl;
}