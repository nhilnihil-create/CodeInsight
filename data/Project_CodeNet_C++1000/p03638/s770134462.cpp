#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;



int main() {
	
	int h, w, n;
	cin >> h >> w >> n;
	vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a[i] = make_pair(tmp, i+1);
	}

	sort(a.begin(), a.end(), greater<pii>());
	vector<vector<int>> c(h, vector<int>(w, 0));
	
	int p = 0;
	for (int i = 0; i < n;i++) {
		for (int j = 0;j < a[i].first;j++) {
			int h1 = p / w;
			int w1 = (p%w);
			if (h1 % 2 == 1) {
				w1 = w - 1 - w1;
			}

			c[h1][w1] = a[i].second;
			p++;

		}
	}

	for (int i = 0; i < h;i++) {
		for (int j = 0; j < w;j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}
