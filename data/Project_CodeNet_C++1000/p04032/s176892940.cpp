#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int n = str.length();
	if (n <= 1)
		cout << "-1 -1";
	else  {
		bool flag = false;
		if (str[1] == str[0]) {
			cout << "1 2";
			flag = true;
		}
		else {
			for (int i=2; i<str.length(); i++) {
				if (str[i] == str[i-1]) {
					cout << i-1+1 << " " << i+1;
					flag = true;
					break;
				}
				if (str[i] == str[i-2]) {
					cout << i-2+1 << " " << i+1;
					flag = true;
					break;
				}
			}
		}

		if (flag == false) {
			cout << "-1 -1";
		}
	}
}