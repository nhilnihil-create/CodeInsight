#include <iostream>
#include <stdlib.h>
#define llint long long

using namespace std;

llint X, Y;

int main(void)
{
	cin >> X >> Y;
	
	if(abs(Y - X) <= 1) cout << "Brown" << endl;
	else cout << "Alice" << endl;
	
	return 0;
}