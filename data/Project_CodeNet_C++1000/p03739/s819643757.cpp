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
const int MOD = 998244353;

ll A[100010];
int main()
{
	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll cnt1 = 0, cnt2 = 0;
	int turn = 1;
	ll num = 0;
	for (int i = 0; i < N; i++) {
		num += A[i];
		if (num * turn <= 0) {
			cnt1 += abs(num - turn);
			num = turn;
		}
		turn *= -1;
	}
	num = 0;
	turn = -1;
	for (int i = 0; i < N; i++) {
		num += A[i];
		if (num * turn <= 0) {
			cnt2 += abs(num - turn);
			num = turn;
		}
		turn *= -1;
	}
	cout << min(cnt1, cnt2) << endl;
}
