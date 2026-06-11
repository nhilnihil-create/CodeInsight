#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int D[11] = {0};
int flag = 0;

bool check(int n)
{
	while(n!=0)
	{
		if(D[n%10] == 1)
		{
			return false;
		}
		n = n/10;
	}
	flag = 1;
	return true;
}


int main()
{
	int N, K, x, i;
	cin >> N >> K;
	for(i=0;i<K;i++)
	{
		cin >> x;
		D[x] = 1;
	}
	int n = N;
	while(flag==0)
	{
		if(check(n))
		{
			break;
		}
		n++;
	}
	cout << n;
  	return 0;
}