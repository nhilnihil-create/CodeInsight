#include <iostream>
using namespace std;

int main()
{
	int A, B, C, D, area1,area2;
	cin >> A >> B >> C >> D;   
	area1 = A * B;
	area2 = C * D;
	if (area1 >= area2)
		cout << area1;
	else
		cout << area2;
	


}