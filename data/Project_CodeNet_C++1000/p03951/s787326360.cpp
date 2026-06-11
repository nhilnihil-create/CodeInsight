#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string s, t;
	cin >> N >> s >> t;
	int ans = 2 * N;
	for (int i = N; i >0; i--) {
		if (s.substr(N - i, i) == t.substr(0, i)) {
			ans = 2 * N - i;
			break;
		}
	}
	cout << ans << endl;
}