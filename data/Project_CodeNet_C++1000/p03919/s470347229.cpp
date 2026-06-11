#include<iostream>
#include<map>
#include<algorithm>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <stack>
#include <string>

using namespace std;

int main() {
	int h, w; cin >> h >> w;
	string s[h][w];
	for (int i = 0; i < h; i++) {
		for (char j = 'A'; j < w+'A'; j++) {
			cin >> s[i][j - 'A'];
			if (s[i][j - 'A'] == "snuke") {
				cout << j << i+1 << endl;
			}
		}
	}
}