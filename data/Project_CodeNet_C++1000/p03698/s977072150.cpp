#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string S;

	cin >> S;

	for (int loop = 0; loop < S.size(); ++loop) {
		for (int loop2 = loop + 1; loop2 < S.size(); ++loop2) {
			if (S.at(loop) == S.at(loop2)) {
				cout << "no" << endl;
				return 0;
			}
		}
	}

	cout << "yes" << endl;

	return 0;
}
