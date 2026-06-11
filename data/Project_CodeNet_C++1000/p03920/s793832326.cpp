#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 10000000;

int sol(int x)
{
	int sum = 0, kai;

	for(int i = 1; i <= x; i++)
	{
		sum += i;

		if (sum >= x)
		{
			kai = i;
			return kai;
		}
	}

	return 0;
}

int main()
{
	int n,num,i,fin,a[MAX/2] = {0};

	cin >> n;

	num = n;
	i = 0;

	while(1)
	{
		a[i] = sol(num);

		num -= a[i];
		if (num == 0)
		{
			fin = i;
			break;
		}
		i++;
	}

	

	for(int j = fin; j >= 0 ; j--)
	{
		cout << a[j] <<endl;
	}


	return 0;
}