#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max], ls[Max];

int main()
{
	int k, s;
	cin >> k >> s;
	ll res = 0;
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i + j > s)break;
			if (i + j + k >= s)res++;
		}
	}
	cout << res << endl;
}