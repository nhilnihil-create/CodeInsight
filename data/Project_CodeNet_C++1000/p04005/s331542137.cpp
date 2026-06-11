#include <iostream>
#include <algorithm>

using namespace std;

long long A[3];
bool even;

void print()
{
	for (int i = 0; i < 3; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	even = false;
	for (int i = 0; i < 3; i++) {
		cin >> A[i];
		if (A[i] % 2 == 0) even = true;
	}
	sort(A, A + 3);

	//print();

	if (even) cout << 0 << endl;
	else cout << A[0] * A[1] << endl;

	return 0;
}