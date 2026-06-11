#include <iostream>

using namespace std;

int main()
{
	long long int a, b;
	cin>>a>>b;
	long long int length = b - a + 1;
	if(a<=0 && b>=0)
		cout<<"Zero";
	else
	{
		if(a>0)
			cout<<"Positive";
		else
		{
			if(length%2)
				cout<<"Negative";
			else
				cout<<"Positive";
		}
	}
}