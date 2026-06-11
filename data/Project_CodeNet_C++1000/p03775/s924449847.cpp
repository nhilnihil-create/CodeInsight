#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int c_get_keta(long long int a) {
	int a_cnt = 0;
	while (a > 0){
		a_cnt++;
		a /= 10;
	}

	return a_cnt;
}

void c_digits_in_multiplication(void) {
	long long int n;
	int min_tmp;
	int ans_min = 10000000;
	cin >> n;
	//int n_end = int(sqrt(long double(n)));
	long int n_end = sqrt(n);

	for (long long int a = 1; a <= (n_end); a++) {
		if (n % a != 0) continue;
		//cout << a << endl;
		long long int b = n / a;
		if (a > b) {
			min_tmp = c_get_keta(a);
		}
		else {
			min_tmp = c_get_keta(b);
		}
		//cout << "n, a,b:" << n<<","<<a << "," << b << endl;
		if (min_tmp < ans_min) ans_min = min_tmp;
	}

	cout << ans_min << endl;
}

int main()
{
	c_digits_in_multiplication();
    return 0;
}