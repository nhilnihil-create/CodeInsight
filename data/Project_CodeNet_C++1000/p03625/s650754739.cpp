#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
int lst[Max];
ll ls[Max];

int main()
{
	int n;
	cin >> n;
	map<int, int> ma;
	int f = 0;
	for (int i = 1;i <= n;i++)
	{
		int t;
		scanf("%d", &t);
		ma[t]++;
		if (ma[t] >= 4) f = 1;
	}
	int g = 0;
	for (auto i = --ma.end();;i--)
	{
		int t = i->second;
		while (t>=2)
		{
			t -= 2;
			g++;
			ls[g] = i->first;
		}
		if (g >= 2) break;
		if (i == ma.begin())break;
	}
	if (g < 2)cout << 0 << endl;
	else cout << ls[1] * ls[2];
}