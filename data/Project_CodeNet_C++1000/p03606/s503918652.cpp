#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 0; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;

int  main()
{
	int n; cin >> n;
	int sum = 0;
	rep(i, n)
	{
		int a, b;
		cin >> a >> b;
		sum += b-a+1;
	}
	cout << sum << endl;
	return 0;
}