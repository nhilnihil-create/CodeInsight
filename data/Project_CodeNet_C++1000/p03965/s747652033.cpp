#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if ((i & 1) && s[i] == 'g') ans++;
		if (!(i & 1) && s[i] == 'p') ans--;
	}
	cout << ans << endl;
}