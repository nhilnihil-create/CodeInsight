#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using P = pair<int,int>;
using pq = priority_queue<int>;
typedef long long ll;
typedef long double ld;
#define pi 3.14159265358979

int  main()
{
	int n; cin >> n;
	vector<int> a(n);
	int f = 0;
	int w = 0;
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] % 4 == 0)
			f++;
		else if (a[i] % 2 == 0)
			w++;
	}

	int sum = f + (w / 2);
	if (f >= n/2)
		cout << "Yes" << endl;
	else if (w == n)
		cout << "Yes" << endl;
	else if (f >= (n-w+1)/2)
	{
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}