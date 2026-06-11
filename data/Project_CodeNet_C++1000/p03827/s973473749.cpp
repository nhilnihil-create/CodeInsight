#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_increment_decrement(void) {
	int x = 0;
	int n;
	string s;
	cin >> n>>s;
	int max=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'I')x++;
		else            x--;

		if (x > max)max = x;
	}
	cout << max << endl;
}

int main()
{
	b_increment_decrement();
    return 0;
}