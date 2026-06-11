#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_not_found(void) {
	int x[140] = { 0 };
	string s;
	int num=0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		x[s[i]]++;
	}
	for (int i = 97; i < 97 + 26; i++) {
		if (x[i] == 0) {
			num = i;
			break;
		}
	}
	if (num == 0) cout << "None" << endl;
	else          printf("%c\n", num);

}

int main()
{
	b_not_found();
    return 0;
}
