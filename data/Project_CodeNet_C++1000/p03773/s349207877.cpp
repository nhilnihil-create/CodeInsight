#include <iostream>
using namespace std;

int main()
{
	int A, B, M;

	cin >> A >> B;
	M = A + B;

	if (M < 24)
		cout << M;
	else if (M > 24)
		cout << M - 24;
	else if (M == 24)
		cout << 0;

}