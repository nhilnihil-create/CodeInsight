#include<bits/stdc++.h>
using namespace std;
int n, num[250007], res[250007];
queue<int>q;
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		num[read()] = i;
	for (int i = 1; i <= n * n; i++)
	{
		if (num[i])
		{
			res[i] = num[i];
			if (q.size() < num[i] - 1)
			{
				cout << "No" << endl;
				return 0;
			}
			for (int j = 1; j <= num[i] - 1; j++)
			{
				res[q.front()] = num[i];
				q.pop();
			}
		}
		else q.push(i);
	}
	while (!q.empty())q.pop();
	for (int i = n * n; i >= 1; i--)
	{
		if (!res[i])q.push(i);
		if (num[i])
		{
			if (q.size() < n - num[i])
			{
				cout << "No" << endl;
				return 0;
			}
			for (int j = 1; j <= n - num[i]; j++)
			{
				res[q.front()] = num[i];
				q.pop();
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n * n; i++)
		printf("%d ", res[i]);
	cout << endl;
	return 0;
}