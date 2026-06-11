#include <iostream>
using namespace std;

int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	if(A!=B&&A!=C&&B!=C)
	{
		cout<<"3";
	}
	else if(A==B&&A==C&&B==C)
	{
		cout<<"1";
	}
	else
	{
		cout<<"2";
	}
	return 0;
}