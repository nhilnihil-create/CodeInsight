#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t;
	cin >> s;
	t = s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		t[i] = i % 2 ? 'p' : 'g';
		if (s[i] == 'g' && t[i] == 'p')
			ans++;
		if (s[i] == 'p' && t[i] == 'g')
			ans--;
	}
	cout << ans << endl;
	return 0;
}