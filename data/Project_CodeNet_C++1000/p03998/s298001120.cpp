#include <bits/stdc++.h>

using namespace std;

int main() {

	string str[3];
	cin >> str[0] >> str[1] >> str[2];

	int now = 0;

	while (true) {

		if (str[now].length() == 0) {

			printf("%c", now + 'A');
			break;

		}

		char top = str[now][0];

		str[now].erase(str[now].begin());

		now = top - 'a';

	}

	return 0;

}