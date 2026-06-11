#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 110;
string a[N];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];
	sort (a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++ )
		cout << a[i];
	cout << '\n';
	
	return 0;
}