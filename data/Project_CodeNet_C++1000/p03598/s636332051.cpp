#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> x(N);
	for (int i = 0; i < N; i++)cin >> x.at(i);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int M = min(x[i], abs(x[i] - K));
		sum += 2*M;
	}
	cout << sum << endl;
}