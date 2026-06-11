#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_sum_of_three_integers(void) {
	int k, s;
	int cnt = 0;
	cin >> k >> s;
	for (int h = 0; h <= k; h++) {
		for (int i = 0; i <= k; i++) {
			int z = s - h - i;
			if ((z >= 0) && (z <= k))cnt++;
		}
	}
	cout << cnt << endl;
}

int main()
{
	b_sum_of_three_integers();
    return 0;
}