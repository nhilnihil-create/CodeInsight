
// C - Colorful Leaderboard

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	set<int> color;
	int any_color = 0;

	int a;
	for (int i=0; i<N; i++) {
		cin >> a;

		if (a <= 399) color.insert(1);
		else if (a <= 799) color.insert(2);
		else if (a <= 1199) color.insert(3);
		else if (a <= 1599) color.insert(4);
		else if (a <= 1999) color.insert(5);
		else if (a <= 2399) color.insert(6);
		else if (a <= 2799) color.insert(7);
		else if (a <= 3199) color.insert(8);
		else any_color++;
	}

	int ans1 = color.size() == 0 ? 1 : color.size();
	int ans2 = color.size() + any_color;

	cout << ans1 << " " << ans2 << endl;

	return 0;
}