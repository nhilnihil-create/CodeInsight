#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	string S;
	cin >> S;

	bool b = true;
	for (int i = S.size() - 1; i >= 0; ) {
		char ch = S.at(i);
		//cout << "ch:" << ch << endl;

		if (ch == 'm') {
			if (i<4) {
				b = false;
				break;
			}
			else {
				string s = S.substr(i - 4, 5);
				//cout << "m-s:" << s << endl;

				if (s != "dream") {
					b = false;
					break;
				}
			}
			i -= 5;
		}
		else if (ch == 'e') {
			if (i < 4) {
				b = false;
				break;
			}
			else {
				string s = S.substr(i - 4, 5);
				//cout << "e-s:" << s << endl;

				if (s != "erase") {
					b = false;
					break;
				}
			}
			i -= 5;
		}
		else if (ch == 'r') {
			if (i < 5) {
				b = false;
				break;
			}
			else {
				string s = S.substr(i - 2, 3);
				if (s != "mer" && s!="ser") {
					b = false;
					break;
				}
				else {
					if (s == "mer") {
						s = S.substr(i - 6, 7);
						//cout << "mer-s:" << s << endl;

						if (s != "dreamer") {
							b = false;
							break;
						}
						else {
							i -= 7;
						}
					}
					else if (s == "ser") {
						s = S.substr(i - 5, 6);
						//cout << "ser-s:" << s << endl;

						if (s != "eraser") {
							b = false;
							break;
						}
						else {
							i -= 6;
						}
					}
				}
			}
		}
		else {
			b = false;
			break;
		}
	}

	if (b) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}