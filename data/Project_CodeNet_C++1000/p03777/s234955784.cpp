#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	char a,b; cin >> a >> b;

	if (a == 'D')
	{
		if (b == 'D') cout << 'H';
		else cout << 'D';
	}
	else
		cout << b;
	return (0);
}