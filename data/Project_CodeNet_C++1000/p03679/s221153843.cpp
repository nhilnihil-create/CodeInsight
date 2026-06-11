#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_expired(void) {
	int x, a, b;
	cin >> x >> a >> b;

	if (b >= (a + x + 1)) cout << "dangerous" << endl;
	else if (b > a) cout << "safe" << endl;
	else             cout << "delicious" << endl;

}

int main()
{
    a_expired();
    return 0;
}