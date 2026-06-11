#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> G(N + 1);
	for (auto i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);
	}

	vector<int> list[2];
	bool used[100001];
	memset(used, 0, sizeof(used));
	used[1] = true;
	
	list[0].push_back(1);
	auto index = 0;
	for (auto i = 0; i < G[1].size(); ++i)
	{
		auto next = G[1][i];
		if (used[next])
		{
			continue;
		}

		while (true)
		{
			list[index].push_back(next);
			used[next] = true;

			auto& g = G[next];
			auto found = false;
			for (auto temp : g)
			{
				if (!used[temp])
				{
					found = true;
					next = temp;
					break;
				}
			}

			if (!found)
			{
				break;
			}
		}

		++index;
		if (index >= 2)
		{
			break;
		}
	}

	cout << list[0].size() + list[1].size() << endl;
	for (auto i = (int)list[0].size() - 1; i >= 0; --i)
	{
		cout << list[0][i];
		if (i > 0)
		{
			cout << " ";
		}
	}
	for (auto i = 0; i < list[1].size(); ++i)
	{
		cout << " " << list[1][i];
	}
	cout << endl;

	return 0;
}