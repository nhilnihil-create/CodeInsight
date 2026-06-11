#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ul;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	double sum = 0, avg;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	avg = sum / n;
	int avg2 = avg, s = 0;
	avg2 += (avg - avg2 >= avg2 + 1 - avg) ? 1 : 0;
	for (int i = 0; i < n; i++)
		s += abs(avg2 - a[i]) * abs(avg2 - a[i]);
	cout << s << endl;
	return 0;
}
