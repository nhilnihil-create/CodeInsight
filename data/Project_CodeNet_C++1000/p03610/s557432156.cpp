#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

void b_oddstring(void) {
	string s;
	string out_string = "";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ((i & 0x1) == 0x0) {
			out_string += s[i];
		}
	}
	cout << out_string << endl;
}

int main()
{
	b_oddstring();
    return 0;
}