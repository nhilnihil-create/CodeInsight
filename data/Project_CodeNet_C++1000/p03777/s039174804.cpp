#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_honest_or_dishonest(void) {
	string a, b;
	cin >> a >> b;

	if (a == "H") {
		cout << (b == "H" ? "H" : "D") << endl;
	}
	else {
		cout << (b == "H" ? "D" : "H") << endl;
	}
}

int main()
{
    a_honest_or_dishonest();
    return 0;
}