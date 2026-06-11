#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	unordered_set<int> s;
	for (auto& i : A) {
		cin >> i;
		s.insert(i);
	}
	auto k = s.size();
	cout << (k & 1 ? k : k - 1) << endl;
}
