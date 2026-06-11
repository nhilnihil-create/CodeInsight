#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
	long long a, b, c;
	cin >> a >> b >> c;
	long long x, y, z;
	if(c%2==1)
		x = a * b;
	else
		x = 0;
	if(b%2==1)
		y = a * c;
	else
		x = 0;
	if(a%2==1)
		z = c * b;
	else
		z = 0;
	cout << min(min(x, y), z) << endl;
}