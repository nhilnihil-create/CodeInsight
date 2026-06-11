#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> data(2, vector<int>(N));

	rep(i, N) {
		cin >> data.at(0).at(i) >> data.at(1).at(i);
	}

	int max_val = 0;
	int max_pos = 0;
	rep(i, N) {
		if(data.at(0).at(i) >= max_pos) {
			max_pos = data.at(0).at(i);
			max_val = data.at(1).at(i);
		}
	}

	cout << max_val + max_pos << endl;
}