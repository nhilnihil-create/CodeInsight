#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

/* abc064 c */
int  main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> color;
	int free = 0;
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] < 400)
			color.insert(1);
		else if (a[i] < 800)
			color.insert(2);
		else if (a[i] < 1200)
			color.insert(3);
		else if (a[i] < 1600)
			color.insert(4);
		else if (a[i] < 2000)
			color.insert(5);
		else if (a[i] < 2400)
			color.insert(6);
		else if (a[i] < 2800)
			color.insert(7);
		else if (a[i] < 3200)
			color.insert(8);
		else
			free++;
	}
	if (!color.size() && free)
		cout << 1 << " " << free << endl;
	else
		cout << color.size() << " " << color.size() + free << endl;
	return (0);
}
