#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int N, K;
	cin >> N >> K;
	int x[N];
	int distance = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
		distance += 2 * min(x[i], K - x[i]);
	}
	cout << distance << '\n';
	return (0);
}
