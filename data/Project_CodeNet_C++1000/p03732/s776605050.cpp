
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



int main() {
	int n, w;
	cin >> n >> w;
	vector<vector<int>> obj(4);
	int w1, v1;
	cin >> w1 >> v1;
	obj[0].emplace_back(v1);
	
	for (int i = 1; i < n; i++) {
		int wi, vi;

		cin >> wi >> vi;
		obj[wi - w1].emplace_back(vi);
	}
	
	for (int i = 0; i < 4;i++) {
		sort(obj[i].begin(), obj[i].end(),greater<int>());
		
	}

	vector<vector<int>> sum(4);
	for (int i = 0; i < 4;i++) {
		vector<int> s(obj[i].size() + 1);
		for (int j = 0; j < obj[i].size();j++) {
			s[j+1] = s[j] + obj[i][j];
		}
		sum[i] = s;
		
	}

	int ans = 0;
	for (int i = 0;i <= obj[0].size();i++) {
		for (int j = 0;j <= obj[1].size();j++) {
			for (int k = 0;k <= obj[2].size();k++) {
				if (1LL *i*w1 +1LL * j * (w1 + 1) +1LL * k * (w1 + 2) > w) {
					break;
				}
				int l = obj[3].size();
				l = min((w - (i * w1 + j * (w1 + 1) + k * (w1 + 2))) / (w1 + 3),l);
				ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);

			}
		}
	}
	cout << ans << endl;
}



