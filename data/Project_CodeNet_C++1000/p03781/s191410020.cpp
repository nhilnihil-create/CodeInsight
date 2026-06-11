#include <iostream>
using namespace std;

int main(void)
{
	int X;
	cin >> X;

	long long i = 0;
	for(;;) {
		i++;
		long long sum = (1 + i) * i / 2;
		if (X <= sum) break;
	}
	cout << i << endl;
	return 0;
}
