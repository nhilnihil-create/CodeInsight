#include <iostream>
using namespace std;

int main()
{
	int A,B;
	cin>>A>>B;
	if(A>B)
	{
		if(B==1)
		{
			cout<<"Bob";
		}
		else
		{
		cout<<"Alice";
		}
	}
	else if(B>A)
	{
		if(A==1)
		{
			cout<<"Alice";
		}
		else
		{
		cout<<"Bob";
		}
	}
	else
		cout<<"Draw";
	return 0;
}