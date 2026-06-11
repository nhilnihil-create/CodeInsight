#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a==b||a==b==1)
		cout << "Draw";
	else if ((a > b)&&(b!=1) ||( a == 1&& b>a))
		cout << "Alice";
	else
	/*else if ((a < b) ||( b == 1&&a>b))*/
		cout << "Bob";

}