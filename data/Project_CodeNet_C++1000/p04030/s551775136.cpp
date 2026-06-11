#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_binaric_easy(void) {
	string s;
	cin >> s;
	char ans[20]={' '};
	int ptr = 0;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] == '0') || (s[i] == '1')) {
			ans[ptr++]=s[i];
		}
		else {
			if (ptr != 0) {
				ans[--ptr] = ' ';
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	b_binaric_easy();
    return 0;
}