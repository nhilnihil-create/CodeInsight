#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> et[100000];

int grundy(int v, int p) {
	int g = 0;
	for (int i = 0; i < et[v].size(); i++) {
		if (et[v][i] == p) continue;
		g ^= grundy(et[v][i], v) + 1;
	}
	return g;
}

int main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		et[x].push_back(y);
		et[y].push_back(x);
	}
	
	if (grundy(0, -1)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}