#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_theater(void) {
	int n;
	int l, r;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> l >> r;
		int person = r - l;
		sum += (person+1);
	}

	cout << sum << endl;
}

int main()
{
	b_theater();
    return 0;
}