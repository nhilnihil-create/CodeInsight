#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
	ll h, w;
	cin >> h >> w;
	ll one, two, three;
	vector<ll> s;
	// h devide
	one = h / 3 * w;
	two = (h - (h / 3)) / 2 * w;
	three = h * w - one - two;
	s.push_back(max(max(one, two), three) - min(min(one, two), three));
	ll mind = h * w;
	for (int i = 1; i < h; i++) {
		one = i * w;
		two = (h - i) * (w / 2);
		three = h * w - one - two;
		mind = min(mind, max(max(one, two), three) - min(min(one, two), three));
	}
	s.push_back(mind);
	//w devide
	one = w / 3 * h;
	two = (w - (w / 3)) / 2 * h;
	three = h * w - one - two;
	s.push_back(max(max(one, two), three) - min(min(one, two), three));
	mind = h * w;
	for (int i = 1; i < w; i++) {
		one = i * h;
		two = (w - i) * (h / 2);
		three = h * w - one - two;
		mind = min(mind, max(max(one, two), three) - min(min(one, two), three));
	}
	s.push_back(mind);
	ll ans = *min_element(s.begin(), s.end());
	cout << ans << endl;
	return 0;
}