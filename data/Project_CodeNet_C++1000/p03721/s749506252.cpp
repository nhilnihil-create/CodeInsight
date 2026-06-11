#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;
	map<long long, long long>mp;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		mp[x] += y;
	}
	for (auto p : mp) {
		//cout << p.first<<"_"<<p.second << endl;
		if (p.second < K) {
			K -= p.second;
		}
		else {
			cout << p.first << endl;
			return 0;
		}
	}
	return 0;
}