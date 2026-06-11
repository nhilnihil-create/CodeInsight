#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

void b_a_to_z_string(void) {
	string s;
	int a_index, z_index;
	bool a_detect = false;
	bool z_detect = false;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (!a_detect) {
			if (s[i] == 'A') {
				a_index = i;
				a_detect = true;
			}
		}
		if(!z_detect){
			if (s[s.size() - 1 - i] == 'Z') {
				z_index = s.size() - 1 - i;
				z_detect = true;
			}
		}
		if (a_detect & z_detect) break;
	}

	cout << z_index - a_index + 1 << endl;
}

int main()
{
	b_a_to_z_string();
    return 0;
}