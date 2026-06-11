#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main() {
	string Sa, Sb, Sc;
	cin >> Sa >> Sb >> Sc;

	char first = 'a';

	while (true) {
		if (first == 'a') {
			if (Sa.empty()) {
				cout << 'A' << endl;
				return 0;
			}
			first = Sa[0];
			Sa.erase(0, 1);
		}
		else if (first == 'b') {
			if (Sb.empty()) {
				cout << 'B' << endl;
				return 0;
			}
			first = Sb[0];
			Sb.erase(0, 1);
		}
		else if (first == 'c') {
			if (Sc.empty()) {
				cout << 'C' << endl;
				return 0;
			}
			first = Sc[0];
			Sc.erase(0, 1);
		}
	}
}