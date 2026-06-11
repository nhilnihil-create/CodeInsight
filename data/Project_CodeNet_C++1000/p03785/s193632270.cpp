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

struct rg {
	int t1;
	int t2;
	rg (int v1, int v2) {
		t1 = v1;
		t2 = v2;
	}
};

bool cmp(const rg& a, const rg& b) {
	return a.t1 < b.t1;
}

int main() {

	int N, C, K;
	cin >> N >> C >> K;

	list<rg> v;
	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		v.push_back(rg(t, t + K));
	}

	v.sort(cmp);

	int ans = 0;
	int val = 0;
	rg dv(0, 0);
	while (v.size() != 0) {
		ans += 1;
		dv = v.front();
		v.pop_front();
		val = 1;
		while (v.size() != 0 && v.front().t1 <= dv.t2 && val < C) {
			v.pop_front();
			val += 1;
		}
	}
	
	cout << ans << endl;

	return 0;
}