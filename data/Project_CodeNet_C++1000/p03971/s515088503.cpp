#include<iostream>
using namespace std;
#include<string>
#include<cstring>

int main() {
	int s, a, b;
	int cntb=0, cntl=0;
	string part;
	cin >> s >> a >> b >> part;
	for (int i = 0; i < s; i++) {
		if (part[i] == 'a') {
			if (cntl < a + b) {
				cntl++;
				cout << "Yes" << endl;
			}
			else cout << "No" << endl;
		}
		else if (part[i] == 'b') {
			if (cntl < a + b && cntb < b) {
				cntl++;
				cntb++;
				cout << "Yes" << endl;
			}
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}