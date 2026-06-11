#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_hotel_easy(void) {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int sum = 0;
	
	if (n > k) {
		sum = x * k + y*(n-k);

	}
	else       sum = x * n;

	cout << sum << endl;
}

int main()
{
    a_hotel_easy();
    return 0;
}