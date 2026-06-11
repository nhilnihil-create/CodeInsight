#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b;
	rep(i, n)
	{
		cin >> a[i];
		if (i % 2 == 0)
			b.push_back(a[i]);
		else
			b.insert(b.begin(), a[i]);
	}
	if(n % 2)
		reverse(b.begin(), b.end());
	rep(i, b.size())
		cout << b[i] << " ";
	cout << endl;
	return 0;
}
