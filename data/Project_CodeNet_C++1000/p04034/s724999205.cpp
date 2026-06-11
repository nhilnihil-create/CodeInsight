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

bool red[100010];
int ball[100010];
int main()
{
	int N, M;
	cin >> N >> M;
	red[0] = true;
	for (int i = 0; i < N; i++) ball[i] = 1;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		if (red[x]) {
			if (ball[x] == 1) {
				red[x] = false;
				red[y] = true;
				ball[x] = 0;
				ball[y]++;
			}
			else {
				red[y] = true;
				ball[x]--;
				ball[y]++;
			}
		}
		else {
			ball[x]--;
			ball[y]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (red[i]) ans++;
	}
	cout << ans << endl;
}