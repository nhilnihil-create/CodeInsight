#include <iostream>
using namespace std;
int main()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int x = A * B;
	int y = C * D;
	if (x > y)
		cout << x;
	else 
	cout << y;
	return 0;
}