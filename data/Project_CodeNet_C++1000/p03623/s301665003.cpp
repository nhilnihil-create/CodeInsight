#include<iostream>
using namespace std;

int main()
{
	int x, a, b,i,j;
	cin >> x >> a >> b;
	i = x - a;
	j = x - b;
	 if (i < 0&&j<0)
	{
	i = -(i);
	j = -(j);
	if (i < j)
		cout << "A";
	else
		cout << "B";
	}
	else if (i < 0)
	{
		i = -(i);
		//j = -(j);
		if (i < j)
			cout << "A";
		else
			cout << "B";

	}
	else if (j < 0)
	{
		j = -(j);
		if (i < j)
			cout << "A";
		else
			cout << "B";
	}
	
	else
	 {
		 if (i < j)
			 cout << "A";
		 else
			 cout << "B";
	 }
}