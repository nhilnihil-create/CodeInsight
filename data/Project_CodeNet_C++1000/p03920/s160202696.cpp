#include <iostream>
using namespace std;

int N;
int ma;
int main()
{
	cin >> N;
	for(int i = 1;i <= N;i++)
	{
		if((i + 1) * i / 2 >= N)
		{
			ma = i;
			break;
		}
	}

	for(int i = ma;i >= 1;i--)
	{
		if(N - i >= 0)
		{
			cout << i << endl;
			N -= i;
		}
	}
	return 0;
}
