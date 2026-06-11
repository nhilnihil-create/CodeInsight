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


struct distanceData {
	int distance, id;
};

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> a(N), b(N), c(M), d(M);
	vector<distanceData> dist(M);
	for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
	for (int i = 0; i < M; i++) cin >> c[i] >> d[i];

	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < M; j++) {
			dist[j] = distanceData{ abs(a[i] - c[j]) + abs(b[i] - d[j]), j+1 };
		}
		auto result = *min_element(dist.begin(), dist.end(),
			[](const distanceData& l, const distanceData& r)->int {
				if (l.distance == r.distance) return l.id < r.id;
				else return l.distance < r.distance;
			});
		print(result.id);
	}
}