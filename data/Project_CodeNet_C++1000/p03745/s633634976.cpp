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
	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	int ans = 0;
	bool d = false, u = false;
	for (int i = 0; i < N; i++) {
		if (!u && !d) {
			if (A[i] < A[i + 1]) u = true;
			else if (A[i] > A[i + 1]) d = true;
			continue;
		}
		else if (u) {
			if (A[i] > A[i + 1]) {
				ans++;
				u = false;
				d = false;
			}
		}
		else if (d) {
			if (A[i] < A[i + 1]) {
				ans++;
				u = false;
				d = false;
			}
		}
	}
	if (u || d) ans++;
	cout << ans << endl;
}
