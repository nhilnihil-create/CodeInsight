#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
typedef long long ll;
const ll MOD = (ll)1e9 + 7LL;
using namespace std;

ll T[100002], A[100002];

int main () {
	ll N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> T[i];
	}
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	ll ans = 1;
	for(int i = 1; i <= N; i++)
	{
		bool upd_T = (T[i-1] != T[i]);
		bool upd_A = (A[i+1] != A[i]);
		if(upd_A && upd_T) {
			if(A[i] != T[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
		if(upd_A && !upd_T) {
			if(A[i] > T[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
		if(!upd_A && upd_T) {
			if(A[i] < T[i]) {
				cout << 0 << endl;
				return 0;
			}
		}
		if(!upd_A && !upd_T) {
			ans *= min(A[i], T[i]);
			ans %= MOD;
		}
	}
	cout << ans << endl;
}
