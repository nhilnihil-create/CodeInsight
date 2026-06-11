#include <iostream>

using namespace std;

int main()	{
  	int n, k, x, y;
  	long long amount = 0;
  	cin >> n >> k >> x >> y;
  	if (n <= k)
      	amount = (n * x);
  	else
  		amount = (k * x) + ((n - k) * y);
  	cout << amount << endl;
	return 0;
}