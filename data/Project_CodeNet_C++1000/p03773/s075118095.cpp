#include <iostream>
using namespace std;
int main()
{
	int A,B;
	cin>>A>>B;
	if(A+B<24)
	{
		cout<<A+B;
	}
	else
	{
		cout<<(A+B)-24;
	}

	return 0;
}