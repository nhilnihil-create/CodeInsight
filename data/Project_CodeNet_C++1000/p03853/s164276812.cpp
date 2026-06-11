#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n, m;
	cin >> n >> m;
	char c[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << c[i][j];
		}
		cout << endl;
		for (int j = 0; j < m; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}
	
		return 0;
}