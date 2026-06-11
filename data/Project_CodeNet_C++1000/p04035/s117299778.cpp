#include <bits/stdc++.h>

using namespace std;

int A[100005];
int N,L;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int pos = -1;

	cin >> N >> L;
	for(int i=1;i<=N;i++)
	{
		cin >> A[i];
	}

	for(int i=N-1;i>=1;i--)
	{
		if(A[i] + A[i+1] >= L)
		{
			pos = i;
			break;
		}
	}

	if(pos==-1)
	{
		cout << "Impossible" << '\n';
		return 0;
	}

	cout << "Possible" << '\n';
	for(int i=1;i<pos;i++)
	{
		cout << i << '\n';
	}
	for(int i=N-1;i>pos;i--)
	{
		cout << i << '\n';
	}
	cout << pos << '\n';

	return 0;
}