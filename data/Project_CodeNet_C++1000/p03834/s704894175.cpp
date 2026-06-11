#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_haiku(void) {
	string s;
	cin >> s;
	s[5] = ' ';
	s[13] = ' ';
	cout << s << endl;
}

int main()
{
    a_haiku();
    return 0;
}