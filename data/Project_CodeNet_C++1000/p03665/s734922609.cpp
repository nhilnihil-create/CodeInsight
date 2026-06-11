#include <bits/stdc++.h>
using namespace std;

void comb_array(long long n, vector<long long> *pnC)
{ // nCk mod MODNUMBER
	(*pnC)[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		(*pnC)[i] = (*pnC)[i - 1] * (n - i + 1) / i;
	}
	if ((*pnC)[n] != 1)
	{
		printf("error");
	}

	return;
}

int main()
{
	//cin.tie(0);
	//ios::sync_with_stdio(false);

	long long N, P;
	scanf("%lld %lld", &N, &P);

	long long A;
	long long even = 0, odd = 0;
	for (long long i = 0; i < N; i++)
	{
		cin >> A;
		if (A % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
	}
	// cout << even << " " << odd << "\n";

	long long result;
	vector<long long> combination(odd + 1);
	comb_array(odd, &combination);

	if (P == 0)
	{
		result = 0;
		for (int i = 0; i <= odd; i = i + 2)
		{
			result += combination[i];
		}
	}
	else
	{
		result = 0;
		for (int i = 1; i <= odd; i = i + 2)
		{
			result += combination[i];
		}
	}
	// cout << result << "\n";
	for (int i = 1; i <= even; i++)
	{
		result = result * 2;
	}

	cout << result;
	return 0;
}