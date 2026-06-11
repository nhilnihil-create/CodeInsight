#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

struct Info {
	long long x;
	long long y;
	Info(long long x, long long y) {
		this->x = x;
		this->y = y;
	}
};

// ���l x �Ń\�[�g���邽�߂̔�r���Z�q
bool cmp_x(const Info& a, const Info& b) {
	return a.x < b.x;
}

// ���l y �Ń\�[�g���邽�߂̔�r���Z�q
bool cmp_y(const Info& a, const Info& b) {
	return a.y < b.y;
}

int main() {

	long long W, H, N;
	cin >> W >> H >> N;

	vector<vector<Info>> val(4, vector<Info>());

	long long x, y, a;
	for (long long i = 0; i < N; i++) {
		cin >> x >> y >> a;
		a--;
		val[a].push_back(Info(x, y));
	}

	for (long long i = 0; i < 4; i++) {
		if (i == 0 || i == 1) {
			sort(val[i].begin(), val[i].end(), cmp_x);
		}
		else {
			sort(val[i].begin(), val[i].end(), cmp_y);
		}
	}

	long long x_min = 0;
	long long x_max = W;
	long long y_min = 0;
	long long y_max = H;
	
	if (val[0].size() != 0) {
		x_min = val[0][val[0].size() - 1].x;
	}
	if (val[1].size() != 0) {
		x_max = val[1][0].x;
	}
	if (val[2].size() != 0) {
		y_min = val[2][val[2].size() - 1].y;
	}
	if (val[3].size() != 0) {
		y_max = val[3][0].y;
	}

	if (x_min < x_max) {
		x = x_max - x_min;
	}
	else {
		x = 0;
	}

	if (y_min < y_max) {
		y = y_max - y_min;
	}
	else {
		y = 0;
	}

	cout << x * y << endl;

	return 0;
}