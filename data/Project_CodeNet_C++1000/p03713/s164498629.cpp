#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	long H, W, ans = LONG_MAX;
	cin >> H >> W;
	for (long i = 1; i < H; i++) {
		long a = LONG_MAX;
		pair<long, long> h1(i, H - i);
		pair<long, long> h2(h1.first / 2, h1.first - h1.first / 2);
		pair<long, long> h3(h1.second / 2, h1.second - h1.second / 2);
		pair<long, long> w(W / 2, W - W / 2);
		vector<long> s;
		s.push_back(h1.first * W);
		s.push_back(h1.second * w.first);
		s.push_back(h1.second * w.second);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		s.clear();
		s.push_back(h1.first * w.first);
		s.push_back(h1.first * w.second);
		s.push_back(h1.second * W);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		s.clear();
		s.push_back(h1.first * W);
		s.push_back(h3.first * W);
		s.push_back(h3.second * W);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		s.clear();
		s.push_back(h2.first * W);
		s.push_back(h2.second * W);
		s.push_back(h1.second * W);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		ans = min(a, ans);
	}
	for (long i = 1; i < W; i++) {
		long a = LONG_MAX;
		pair<long, long> h(H / 2, H - H / 2);
		pair<long, long> w1(i, W - i);
		pair<long, long> w2(w1.first / 2, w1.first - w1.first / 2);
		pair<long, long> w3(w1.second / 2, w1.second - w1.second / 2);
		vector<long> s;
		s.push_back(H * w1.first);
		s.push_back(h.first * w1.second);
		s.push_back(h.second * w1.second);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		s.clear();
		s.push_back(h.first * w1.first);
		s.push_back(h.second * w1.first);
		s.push_back(H * w1.second);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		s.clear();
		s.push_back(H * w1.first);
		s.push_back(H * w3.first);
		s.push_back(H * w3.second);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		s.clear();
		s.push_back(H * w2.first);
		s.push_back(H * w2.second);
		s.push_back(H * w1.second);
		if (none_of(s.begin(), s.end(), [](long& a) { return !a; })) {
			a = min(*max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end()), a);
		}
		ans = min(a, ans);
	}
	cout << ans;
}