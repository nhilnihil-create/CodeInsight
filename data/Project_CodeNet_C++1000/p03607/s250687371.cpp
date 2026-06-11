#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#define PRE std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
ll lst[Max];
int ls[Max];

int main()
{
	PRE
	int n;
	cin >> n;
	map<int, int> ma;
	for (int i = 1;i <= n;i++)
	{
		int t;
		cin >> t;
		ma[t]++;
	}
	int sum = 0;
	for (auto i = ma.begin();i != ma.end();i++)
	{
		if (i->second % 2 == 1)sum++;
	}
	cout << sum;
}