#include<iostream>
using namespace std;
int main()
{
	int n, m; cin >> n >> m; char a[108][106];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= m+1; ++i)
	{
		cout << '#';
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << '#';
		for (int j = 0; j < m; ++j)
		{
			cout << a[i][j];
		}
		cout << "#"<<endl;
	}
	for (int i = 0; i <= m+1; ++i)
	{
		cout << '#';
	}
}