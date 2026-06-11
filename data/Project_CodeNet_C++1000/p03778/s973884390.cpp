#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int w, a, b, tmp;
  	cin >> w >> a >> b;
  	tmp = abs( a - b );
  	if( tmp <= w )
		cout << 0;
  	else cout << tmp - w;
}