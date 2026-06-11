#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
const ll MOD = 1e9+7;
ll T[MAX_N],A[MAX_N];

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		cin >> T[i];
	}
	rep(i,N)
	{
		cin >> A[i];
	}

	ll ans = 1;
	if (A[0] < T[0])
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = 1; i < N-1; ++i)
	{
		bool flag1 = false, flag2 = false;
		if (T[i-1] < T[i])
		{
			flag1 = true;
		}
		if (A[i] > A[i+1])
		{
			flag2 = true;
		}

		if (flag1 && flag2)
		{
			if (T[i] != A[i])
			{
				cout << 0 << endl;
				return 0;
			}
		}
		else if (flag1 && !flag2)
		{
			if (A[i] < T[i])
			{
				cout << 0 << endl;
				return 0;
			}
		}
		else if (!flag1 && flag2)
		{
			if (T[i] < A[i])
			{
				cout << 0 << endl;
				return 0;
			}
		}
		else
		{
			ans = ans * min(T[i],A[i]) % MOD;
		}
	}
	if (T[N-1] < A[N-1])
	{
		cout << 0 << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}