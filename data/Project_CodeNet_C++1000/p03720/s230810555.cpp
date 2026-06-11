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
		cout << cnt[i] << endl;
	}
}