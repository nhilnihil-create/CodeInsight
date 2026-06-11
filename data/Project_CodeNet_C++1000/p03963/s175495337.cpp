#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_atcoder_boal(void) {
	int n,k;
	cin >> n >> k;
	long long int pat = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1)pat += k;
		else       pat *= (k - 1);
	}
	cout << pat << endl;
}

int main()
{
	b_atcoder_boal();
    return 0;
}