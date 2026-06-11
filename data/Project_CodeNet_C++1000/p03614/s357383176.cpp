#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> p;

int main()
{
	cin >> n;
	p.resize(n + 1);

	for(int i = 1;i <= n;i++)
	{
		cin >> p[i];
	}

	int result = 0;

	for(int i = 1;i < n;i++)
	{
		if(p[i] == i)
		{
			swap(p[i] , p[i + 1]);
			result++;
		}
	}

	if(p[n] == n) result++;

	cout << result << endl;
	return 0;
}
