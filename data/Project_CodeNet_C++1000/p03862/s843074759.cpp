#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N{}, x{};
	cin >> N >> x;
	vector<int>a(N);
	for (size_t i = 0;i < N;++i)
	{
		cin >> a.at(i);
	}
	long long oper = 0;
	for (size_t i = 0;i < N - 1;++i)
	{
		if (a.at(i) + a.at(i + 1) > x)
		{
			int d = a.at(i) + a.at(i + 1) - x;
			if (d <= a.at(i + 1))
			{
				a.at(i + 1) = a.at(i + 1) - d;
				oper += d;
			}
			else
			{
				a.at(i + 1) = 0;
				a.at(i) = a.at(i) - (d - a.at(i + 1));
				oper += d;
			}
		}
	}
	cout << oper << endl;
}