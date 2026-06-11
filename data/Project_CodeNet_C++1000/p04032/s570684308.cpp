#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a = 0;
	string S;
	cin >> S;

	if (S.size() == 2) {
		if (S.at(0) == S.at(1))
			cout << "1 2" << endl;
		else cout << "-1 -1" << endl;
		return 0;
	}


	for (int i = 2; i < S.size(); i++) {
		if (S.at(i - 2) == S.at(i - 1)) {
			cout << i - 1 << ' ' << i << endl;
			return 0;
		}
		else if (S.at(i - 2) == S.at(i)) {
			cout << i - 1 << ' ' << i + 1 << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}