#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_comparison(void) {
	string a, b;
	string o_msg="EQUAL";
	cin >> a >> b;
	if (a.size() > b.size()) o_msg = "GREATER";
	else if (a.size() < b.size()) o_msg = "LESS";
	else {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i])     continue;
			else if (a[i] > b[i]) {
				o_msg = "GREATER";
				break;
			}
			else {
				o_msg = "LESS";
				break;
			}
		}
	}
	cout << o_msg << endl;
}

int main()
{
	b_comparison();
    return 0;
}