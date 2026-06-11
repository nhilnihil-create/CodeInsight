#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_two_switches(void) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int cnt[110] = { 0 };
	for (int i = a; i < b; i++) cnt[i]++;
	for (int i = c; i < d; i++) cnt[i]++;
	int overlap = 0;
	for (int i = 0; i <= 100; i++) {
		if (cnt[i] == 2) overlap++;
	}
	cout << overlap << endl;
}

int main()
{
	b_two_switches();
    return 0;
}