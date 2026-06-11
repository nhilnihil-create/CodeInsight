
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
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;

const int SIZE = 500;

int main() {
	int n, ma, mb;
	cin >> n >> ma >> mb;

	vector<vector<int>> cost(SIZE, vector<int>(SIZE,BIG_INT));

	cost[0][0] = 0;
	for (int i = 0;i < n;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = SIZE - 1; j >= a;j--) {
			for (int k = SIZE - 1;k >= b; k--) {
				
				cost[j][k] = min(cost[j][k], cost[j - a][k - b] + c);
				
			}
		}

	}

	
	int ans = BIG_INT;
	int sum_a = ma;
	int sum_b = mb;
	while (sum_a < SIZE && sum_b < SIZE) {
		ans = min(ans, cost[sum_a][sum_b]);
		
		sum_a += ma;
		sum_b += mb;
	}
	if (ans == BIG_INT) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
}
