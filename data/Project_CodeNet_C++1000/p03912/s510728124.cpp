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

int X[100010];
int cnt[100010];
int same[100010];
int c[100010];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		cnt[X[i] % M]++;
		c[X[i]]++;
	}
	for (int i = 0; i < 100010; i++) {
		same[i % M] += c[i] / 2;
	}
	int ans = cnt[0] / 2;
	//cout << ans << endl;
	if (M % 2 == 0) ans += cnt[M / 2] / 2;
	//cout << ans << endl;
	for (int i = 1; i <= (M - 1) / 2; i++) {
		ans += min(cnt[i], cnt[M - i]);
		if (cnt[i] >= cnt[M - i]) {
			int sum = cnt[i] - cnt[M - i];
			ans += min(sum / 2, same[i]);
		}
		else {
			int sum = cnt[M - i] - cnt[i];
			ans += min(sum / 2, same[M - i]);
		}
		//cout << same[i] << " " << same[M - i] << endl;
		//cout << ans << endl;
	}
	cout << ans << endl;
}
