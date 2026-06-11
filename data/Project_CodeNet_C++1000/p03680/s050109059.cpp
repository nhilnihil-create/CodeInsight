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
bool F[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[i + 1] = a;
	}
	int ans = 0;
	int b = 1;
	while (b != 2) {
		if (F[b]) {
			cout << -1 << endl;
			return 0;
		}
		F[b] = true;
		ans++;
		b = A[b];
	}
	cout << ans << endl;
}
