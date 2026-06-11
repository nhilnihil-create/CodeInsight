#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_training_camp(void) {
	long long int n;
	long long int power = 1;
	const int a = 1000000007;

	cin >> n;
	for (long long int i = 1; i <= n; i++) {
		power = power*i;
		power = power % a;
		
	}
	cout << power << endl;
	//cout << power % (a) << endl;
}

int main()
{
	b_training_camp();
    return 0;
}