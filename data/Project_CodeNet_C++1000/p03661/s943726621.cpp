#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll *a = new ll[n];
	ll* b = new ll[n];
	int tmp = 0;
	while (n--)
		cin >> a[tmp++];
	b[0] = a[0];
	for (int i = 1; i < tmp; i++)
		b[i] =b[i-1]+ a[i];
	ll min = abs(b[tmp-1] - 2 * b[0]);
	for (int i = 1; i < tmp - 1; i++)
		min =((min > abs(b[tmp-1] - 2 * b[i])) ? (abs(b[tmp-1] - 2 * b[i])) : min);
	cout << min << endl;
	return 0;
}