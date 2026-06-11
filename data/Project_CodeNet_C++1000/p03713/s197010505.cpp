#include <iostream>
#include <vector>
#include <algorithm> // sort
using namespace std;

int diff_S(int a, int b, int c) {
	vector<int> vec(3);
	vec[0] = a * c;
	vec[1] = (a/2) * (b-c);
	vec[2] = (a-a/2) * (b-c);
	sort(vec.begin(), vec.end());
	return vec[2] - vec[0];
}

int main() {
	int H, W;
	cin >> H >> W;
	
	if (H%3==0 || W%3==0) {
		cout << 0 << endl;
		return 0;
	}

	int ans = min(H, W);
	ans = min(ans, diff_S(H, W, W/3));
	ans = min(ans, diff_S(H, W, W/3+1));
	ans = min(ans, diff_S(W, H, H/3));
	ans = min(ans, diff_S(W, H, H/3+1));
	cout << ans << endl;
	return 0;
}
