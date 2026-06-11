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

int T[100010];
int main()
{
	int N, C, K;
	cin >> N >> C >> K;
	for (int i = 0; i < N; i++) cin >> T[i];
	sort(T, T + N);
	int ans = 0;
	int time = 0;
	int cnt = 0;
	int i = 0;
	while (true) {
		time = T[i] + K;
		cnt = 1;
		i++;
		while (T[i] <= time && cnt < C) {
			cnt++;
			i++;
			if (i >= N) break;
		}
		ans++;
		if (i >= N) break;
	}
	cout << ans << endl;
}