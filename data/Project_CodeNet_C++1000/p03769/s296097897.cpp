#include <iostream>
#include<math.h>
using namespace std;
long long n;

int main()
{
	cin >> n;
	int x[50];
	n++;
	int i, flg = 0;
	for (i = 0; i < 50 && n>0; i++) {
		x[i] = n&1;
		n >>= 1;
		if ( n&& x[i])
			flg = 1;
	}
	if (!flg) {
		cout << i << endl;
		cout << "1";
		for (int j = 2; j <= i; j++)
			cout << " 1";
		return 0;
	}
	int y[101],z[101];
	int a=0,b = 0,c=100;
	for (int j = 0; j <i-1; j++) {
		if (x[j]) {
			z[++b] = c--;
			y[++a] = c--;
		}
		else {
			y[++a] = c--;
		}
	}
	cout << 200 - c*2<< endl;
	cout << z[1];
	for (int j = 2; j <= b; j++)
		cout << " "<<z[j];
	for (int j = a; j >=1; j--)
		cout << " "<<y[j] ;
	for (int j = c + 1; j <= 100; j++)
		cout << " " << j;
}

