#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int>road(n,0);
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		road[tmp1-1]++; road[tmp2-1]++;
	}
	for (auto&& x : road) {
		cout << x << endl;
	}

	return 0;
}