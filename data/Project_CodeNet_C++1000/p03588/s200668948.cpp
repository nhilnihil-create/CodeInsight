#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> AB(N);
	for (pair<int, int>& i : AB) cin >> i.first >> i.second;
	sort(AB.begin(), AB.end());
	cout << AB.back().first + AB.back().second;
}