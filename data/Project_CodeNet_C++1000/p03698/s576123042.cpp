#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_varied(void) {
	string s;
	int cnt[27] = { 0 };
	string msg = "yes";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int ptr = s[i] - 'a';
		cnt[ptr]++;
	}

	for (int i = 0; i < 27; i++) {
		if (cnt[i] > 1) {
			msg = "no";
			break;
		}
	}
	cout << msg << endl;
}


int main()
{
	b_varied();
    return 0;
}