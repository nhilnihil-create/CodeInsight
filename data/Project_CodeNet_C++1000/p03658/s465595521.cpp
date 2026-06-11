#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_snake_toy(void) {
	int n, k;
	int l[50];
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> l[i];

	sort(l, l + n);
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += l[n - i - 1];
	}
	cout << sum << endl;
}

int main()
{
	b_snake_toy();
    return 0;
}