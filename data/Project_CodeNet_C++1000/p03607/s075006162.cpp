#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


int main() {
	int N, a; cin >> N;
	unordered_set<int> ren;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (ren.find(a) == ren.end()) {
			ren.insert(a);
		}
		else {
			ren.erase(a);
		}
	}
	print(ren.size());
}