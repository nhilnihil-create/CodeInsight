#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_collectiong_balls(void) {
	int n, k;
	int* x;
	cin >> n >> k;
	x = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)cin >> x[i];
	int sum = 0;
	int sub_a, sub_b;
	for (int i = 0; i < n; i++) {
		sub_a = abs(x[i]);
		sub_b = abs(k - x[i]);
		if (sub_a < sub_b) sum += sub_a<<1;
		else               sum += sub_b<<1;
	}

	cout << sum << endl;

	free(x);
}

int main()
{
	b_collectiong_balls();
    return 0;
}