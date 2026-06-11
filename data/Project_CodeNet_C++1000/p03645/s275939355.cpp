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

bool E[200010];
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (a > b) swap(a, b);
		if (a == 0) V.push_back(b);
		if (b == N - 1) E[a] = true;
	}
	for (int A : V) {
		if (E[A]) {
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}