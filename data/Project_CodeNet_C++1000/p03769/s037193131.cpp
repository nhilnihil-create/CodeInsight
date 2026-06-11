#include <iostream>
#include <vector>
using namespace std;

const long long N = 1000ll * 1000 * 1000 * 1000 + 5;
const int X = 90;

vector <int> ans;
int get(long long x, int y) {
	return (x >> y) & 1;
}
int main() {
	long long n;
	cin >> n;
	for (int i = 1; i <= X; i++) {
		ans.push_back(i);
	}
	int x = 0;
	for (x = 0; x <= X; x++) {
		if (n >= (1ll << x)) {
			n -= (1ll << x);
		//	ans.push_back(x + 1);
		}
		else {
			break;
		}
	}
//	cout << x << endl;
	for (int i = 0; i < x; i++) {
		if (get(n, i)) {
			ans.push_back(X - i);
		}
		ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
