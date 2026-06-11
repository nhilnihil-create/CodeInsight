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

int A[110];
int main()
{
	int K, T;
	cin >> K >> T;
	for (int i = 0; i < T; i++) cin >> A[i];
	sort(A, A + T, greater<int>());
	int ans = A[0] - 1;
	for (int i = 1; i < T; i++) {
		ans -= A[i];
	}
	cout << max(0, ans) << endl;
}
