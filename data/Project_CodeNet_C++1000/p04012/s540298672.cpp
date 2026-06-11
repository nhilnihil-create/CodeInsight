#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_beautiful_words(void) {
	string w;
	int cnt[26] = { 0 };
	cin >> w;
	for (int i = 0; i < w.size(); i++) {
		//cout << i;
		int index = w[i] - 'a';
		cnt[index]++;
	}
	bool beautiful = true;
	for (int i = 0; i < 26; i++) {
		if ((cnt[i] & 0x1) == 0x1) {
			beautiful = false;
			break;
		}
	}

	if (beautiful) cout << "Yes" << endl;
	else           cout << "No" << endl;
}

int main()
{
	b_beautiful_words();
    return 0;
}