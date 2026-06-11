#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll box[100005] = {};
ll red[100005] = {};
int main() {
	int n, m;
	cin >> n >> m;
	int x, y;
	ll count = 0;
	for (int i = 0; i < n; i++) {
		box[i] = 1;
	}
	red[0] = 1;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--; y--;
		box[x]--;
		box[y]++;
		if (red[x] != 0) {
			red[y] = 1;
			if (box[x] == 0) {
				red[x] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (box[i] > 0&&red[i]>0) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}