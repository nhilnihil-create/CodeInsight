#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

char a_grouping_sub(int n) {
	if (n == 2) return 'C';
	else if ((n == 4) || (n == 6) || (n == 9) || (n == 11)) return 'B';
	else return 'A';
}

void a_grouping(void) {
	int x, y;
	cin >> x >> y;

	if (a_grouping_sub(x) == a_grouping_sub(y)) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main()
{
    a_grouping();
    return 0;
}