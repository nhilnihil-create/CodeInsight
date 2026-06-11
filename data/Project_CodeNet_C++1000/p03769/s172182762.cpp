#include<bits/stdc++.h>
using namespace std;
long long n, v;
list<int>a, b;
void solve()
{
	if (!n)return;
	if (n % 2 == 1)
		n >>= 1, solve(), v++, a.insert(a.begin(), v), b.insert(b.begin(), v);
	else n--, solve(), v++, a.insert(a.begin(), v), b.insert(b.end(), v);
}
int main()
{
	cin >> n;
	solve();
	cout << a.size() + b.size() << endl;
	for (list<int>::iterator i = a.begin(); i != a.end(); i++)
		cout << *i << ' ';
	for (list<int>::iterator i = b.begin(); i != b.end(); i++)
		cout << *i << ' ';
	cout << endl;
	return 0;
}