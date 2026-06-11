#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1]) {
			printf("%d %d\n", i + 1, i + 2);
			return 0;
		}
	}
	for (int i = 0; i < s.length() - 2; i++) {
		if (s[i] == s[i + 2]) {
			printf("%d %d\n", i + 1, i + 3);
			return 0;
		}
	}
	cout << "-1 -1" << endl;

	return 0;
}