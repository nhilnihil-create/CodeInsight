#include <iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> N(n);

	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}

	int m;
	cin >> m;
	vector<int> P(m), X(m);

	for (int i = 0; i < m; i++) {
		cin >> P[i] >> X[i];
	}

	for (int i = 0; i < m; i++) {
		int tmp = N[P[i] - 1];
		N[P[i] - 1] = X[i];

		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum = sum + N[j];
		}
		cout << sum << endl;
		N[P[i] - 1] = tmp;
	}
}