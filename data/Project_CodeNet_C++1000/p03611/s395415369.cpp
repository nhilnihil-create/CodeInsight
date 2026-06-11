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

int cnt[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	int ans = 0;
	for (int i = 1; i < 100000; i++) {
		ans = max(ans, cnt[i - 1] + cnt[i] + cnt[i + 1]);
	}
	cout << ans << endl;
}
