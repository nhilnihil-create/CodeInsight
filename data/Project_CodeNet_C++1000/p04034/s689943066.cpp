#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	int N, M;
	cin >> N >> M;

	vector<int> ball(N, 1);
	vector<bool> red(N, false);
	red[0] = true;

	int x, y;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		x--;
		y--;
		if (red[x] == true) {
			if (ball[x] == 1) {
				red[x] = false;
			}
			red[y] = true;
		}
		ball[x] -= 1;
		ball[y] += 1;
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (red[i] == true) {
			ans += 1;
		}
	}

	cout << ans << endl;

	return 0;
}