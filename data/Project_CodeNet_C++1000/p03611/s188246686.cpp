#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}
;
int main() {
	int N, a;
	cin >> N;
	vector<int> Xlist(100000 + 3, 0);
	for (int i = 0; i < N; i++) {
		cin >> a;
		Xlist[a+0]++;
		Xlist[a+1]++;
		Xlist[a+2]++;
	}
	print(*max_element(Xlist.begin(), Xlist.end()));
}