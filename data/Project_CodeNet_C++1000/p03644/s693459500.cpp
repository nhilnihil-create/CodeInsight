#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,i; cin >> n;
	for ( i = 1;; i *= 2)
	{
		if (i * 2 > n)
			break;
	}
	cout << i;
}