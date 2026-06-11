#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > map;
int N;
class road {
public:
	int a;
	int b;
	int far;
	road(int c, int d, int e) :a(c), b(d), far(e) {}
};
bool compare(road &a, road &b) {
	return a.far < b.far;
}


bool func(road& a, int num) {
	return a.a != num&&a.b != num;
}

int find(road &ro) {
	int res = (1 << 31) - 1;
	for (int i = 1; i <= N; ++i) {
		if (func(ro, i)) {
			int a = map[i][ro.a];
			int b = map[i][ro.b];
			res = min(res, a + b);
		}
	}
	return res;
}
int main() {
	cin >> N;
	map.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		map[i].resize(N + 1);
		for (int j = 1; j <= N; ++j) {
			cin >> map[i][j];
		}
	}
	vector<road> list;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			list.push_back(road(i, j, map[i][j]));
		}
	}
	sort(list.begin(), list.end(), compare);
	long long ans = 0;
	for (int i = 0; i < list.size(); ++i) {
		int num = find(list[i]);
		int num2 = map[list[i].a][list[i].b];
		if (num > num2) {
			ans += num2;
		}
		else if (num < num2) {
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}