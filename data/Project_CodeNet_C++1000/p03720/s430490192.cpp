#include<bits/stdc++.h>
using namespace std;

int A[55];
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		A[a]++;
		A[b]++;
	}
	for (int i = 1; i <= n; ++i)
		cout << A[i] << endl;
}

