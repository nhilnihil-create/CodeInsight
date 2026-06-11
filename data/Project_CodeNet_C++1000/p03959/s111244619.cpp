#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll T[100010], A[100010];
int main()
{
	int N; cin >> N;
	ll num1 = 0, num2 = 0;
	int p1 = 0, p2 = 0;
	ll ans = 1;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		num1 = max(num1, T[i]);
	}
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		num2 = max(num2, A[i]);
	}
	if (num1 != num2) {
		cout << 0 << endl;
		return 0;
	}
	num1 = 0, num2 = 0;
	for (int i = 0; i < N; i++) {
		if (T[i] > num1) {
			num1 = T[i];
			p1 = i;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] > num2) {
			num2 = A[i];
			p2 = i;
		}
	}
	if (p1 > p2) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < p1; i++) {
		if (T[i] == T[i - 1]) {
			ans = (ans * T[i]) % mod;
		}
	}
	//cout << ans << endl;
	for (int i = N - 2; i > p2; i--) {
		if (A[i] == A[i + 1]) {
			ans = (ans * A[i]) % mod;
		}
	}
	for (int i = 0; i < p2 - p1 - 1; i++) {
		ans = (ans * num1) % mod;
	}
	cout << ans << endl;
}