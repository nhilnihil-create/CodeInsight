#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 7;
int lst[Max];

int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		lst[a]++;
		lst[b]++;
	}
	for (int i = 1; i <= n; i++)cout << lst[i] << endl;
}