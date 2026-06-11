#include <iostream>

using namespace std;

long long N;

int a[200] = {0};
int b[200] = {0};

int numa = 1;
int numb = 1;

int big = 100;

int main()
{
	cin >> N;
	
	N ++;
	while(N > 1)
	{
		if(N % 2)
		{
			a[numa ++] = big --;
			N --;
		}
		else
		{
			b[numb ++] = big --;
			N /= 2;
		}	
	}
	int len = numa + numb - 2;
	len *= 2;
	cout << len << endl;
	for(int i = 103 - numa - numb; i <= 100; i ++)
		cout << i << " ";
	for(int i = 1; i < numa; i ++)
		cout << a[i] << " ";
	for(int i = numb - 1; i >= 1; i --)
		cout << b[i] << " ";
	return 0;	
}