#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> edges(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].push_back(b - 1);
		edges[b - 1].push_back(a - 1);
	}

	long long V = 0, K1 = 0, K2 = 0; 
	vector<int> mark(N, -1);
	
	for (int i = 0; i < N; i++)
	{
		if (mark[i] == -1)
		{
			queue<int> que;
			que.push(i);
			mark[i] = 0;
			bool cycle = false;
			int count = 0;
			while (!que.empty())
			{
				int u = que.front();
				count++;
				que.pop();
				int val = mark[u] ^ 1;
				for (int v : edges[u])
				{
					if (mark[v] == -1)
					{
						mark[v] = val;
						que.push(v);
					}
					else if(mark[v] != val)
						cycle = true;
				}
			}

			if (count == 1)
				V++; 
			else if (cycle)
				K1++;
			else
				K2++;
		}
	}

	cout << K1 * K1 + 2 * K1 * K2 + 2 * K2 * K2 + V * (2 * N - V);
	return 0;
}