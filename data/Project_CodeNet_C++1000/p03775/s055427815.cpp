#include<bits/stdc++.h>
using namespace std;


int F(long long A, long long B)
{
	long long C = max(A,B);
	int n = 0;
	while (C > 0)
	{
		C /= 10;
		n += 1;
	}
	return n;
}

int main()
{
	long long n; cin >> n;
	int m = 1e9;
	for (long long i = 1; i*i <= n; ++i)
	{
		long long j = n / i; 
		if (j * i == n)
			m = min(m, F(i, j));
	}
	cout << m << endl;
}

