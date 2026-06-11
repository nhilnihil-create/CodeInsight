#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;
	reverse(s.begin(), s.end());

	string t = "";
	for (int i = 0; i < s.length(); i++) {
		if (s.substr(i, 5) == "maerd") {
			t += "maerd";
			i += 4;
		}else if (s.substr(i, 7) == "remaerd") {
			t += "remaerd";
			i += 6;
		}else if (s.substr(i, 5) == "esare") {
			t += "esare";
			i += 4;
		}else if (s.substr(i, 6) == "resare") {
			t += "resare";
			i += 5;
		}
	}

	cout << (s == t ? "YES" : "NO") << endl;

	return 0;
}