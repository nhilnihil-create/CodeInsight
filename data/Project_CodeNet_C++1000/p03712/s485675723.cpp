#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 7;
string lst[Max];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> lst[i];
	}
	for (int i = 1; i <= m + 2; i++)printf("#");
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << "#" << lst[i] << "#" << endl;
	}
	for (int i = 1; i <= m + 2; i++)printf("#");
}