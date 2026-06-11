#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_hashira(void) {
	int a, b, c;
	cin >> a >> b >> c;

	cout << (b - a == c - b ? "YES" : "NO") << endl;
}

int main()
{
    a_hashira();
    return 0;
}