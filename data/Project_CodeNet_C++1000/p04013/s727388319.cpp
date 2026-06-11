#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int y[55];
long long int c[52][51][2505];
int main() {
	int n, a;
	
	cin >> n;
	cin >> a;
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	c[1][0][0] = 1;
	c[1][1][y[0]] = 1;
	for (int i = 2; i < n+1; i++) {
		for (int j = 0; j < i+1; j++) {
			for (int k = 0; k <=n * 50; k++) {
				if (k >= y[i-1]) {
					if (j > 0)c[i][j][k] = c[i - 1][j][k] + c[i - 1][j - 1][k - y[i-1]];
				}
				else {
					c[i][j][k] = c[i - 1][j][k];
				}
			}
		}
	}
	long long int sum = 0;
	for (int i = 1; i < n+1; i++) {
		sum += c[n][i][i * a];
	}
	cout << sum;
}