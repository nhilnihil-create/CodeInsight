#include<iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	
	if(a>=1200&&a<=3000)
	{
		cout << "ARC";
	}else if (a<1200&&a<=3000)
	{
		cout << "ABC";
	}
}
