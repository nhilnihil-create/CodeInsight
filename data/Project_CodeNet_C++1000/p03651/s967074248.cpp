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
int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main()
{
	int N, K;
	cin >> N >> K;
	int MAX = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		MAX = max(MAX, A[i]);
	}
	if (K > MAX) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	int num = A[0];
	for (int i = 1; i < N; i++) num = gcd(num, A[i]);
	if (K % num == 0) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
}
