#include <iostream>
using namespace std;
int main()
{
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	if (n <= k)
		cout << n * x << "\n";
	else
		cout << k * x + (n - k) * y << "\n";
}