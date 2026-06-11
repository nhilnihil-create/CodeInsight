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
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int a[100010];
int main()
{
	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N - 1; i++) {
		if (a[i] + a[i + 1] >= L) {
			cout << "Possible" << endl;
			for (int j = 0; j < i; j++) {
				cout << j + 1 << endl;
			}
			for (int j = N - 2; j > i; j--) {
				cout << j + 1 << endl;
			}
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
}