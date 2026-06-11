#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int i;
	int sum = 0;
	vector<int> ans;
	cin >> N;

	for (i = 1; i <= N; i++)
	{
		if (sum > N)
			break;

		sum += i;
	}

	for (int j = 1; j < i; j++)
	{
		if (sum - j != N)
		{
			cout << j << endl;
		}
	}

	return 0;
}
