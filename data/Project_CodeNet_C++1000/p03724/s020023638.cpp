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
const double PI = 3.14159265358979323846264338327950288;

int cnt[100010];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cnt[a]++;
		cnt[b]++;
	}
	for (int i = 0; i < N; i++) {
		if (cnt[i] % 2 == 1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}
