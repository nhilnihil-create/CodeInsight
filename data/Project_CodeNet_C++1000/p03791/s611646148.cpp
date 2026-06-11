#include <iostream>


#define nmax 100010
const long long MOD = 1000000007;

using namespace std;
long long P[nmax];
int n;
int a[nmax];

int main()
{
	cin >> n;
	for (int i =1 ;i<=n; i++ ) cin >> a[i];
	long long res = 1;
	int k = 0;
	//int j = 0;
	P[0] = 1;
	for (int i =1;i<=n;i++) P[i] = (P[i-1] * i) % MOD;
	for (int i = 1;i<=n;i++)	
	{
		if ((i!=n)&& (a[i] == 2*(i-k) -2 ))
		{
			res = (res * (i-k))% MOD;
			k ++;
		}
		if (i==n)
		{
			res = (res * P[n-k]) % MOD;
		}
	}
	cout <<res;
	return 0 ;
}