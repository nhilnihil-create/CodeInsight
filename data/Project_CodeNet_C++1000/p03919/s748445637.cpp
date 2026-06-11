# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
constexpr int MOD = 1000000000 + 7;
constexpr int INF = 2000000000;
using namespace std;


int main() {
	int h, w;
	cin >> h >> w;
	string s;
	for (int i = 1; i <= h; i++) {
		for (int j = 'A'; j < 'A' + w; j++) {
			cin >> s;
			if (s == "snuke") {
				cout << char(j) << i << endl;
			}
		}
	}
}