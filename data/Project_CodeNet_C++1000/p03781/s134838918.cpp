#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x;

int main()
{
	int n = 0;

	cin >> x;

	while(x > (n + 1) * n / 2) n++;


	cout << n << endl;
	return 0;
}
