#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_ss(void) {
	string s;
	cin >> s;
	int num = 1;

	for (int i = 1; i < s.size()-1; i++) {
		string sub_s = s.substr(0, s.size() - i);
		if ((sub_s.size() & 0x1) == 0x1)continue;
		int half = sub_s.size() >> 1;
		string sub_s_upper = sub_s.substr(0, half);
		string sub_s_lower = sub_s.substr(half, sub_s.size());
		if (sub_s_upper == sub_s_lower) {
			num = sub_s.size();
			break;
		}
	}

	cout << num << endl;
}

int main()
{
	b_ss();
    return 0;
}