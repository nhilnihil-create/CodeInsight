#include<iostream>
#include<string>
using namespace std;
struct ST
{
	int S;
	int T;
	ST()
	{
		S = T = 0;
	}
};

int main()
{
	string str;
	cin >> str;
	ST st[200010];
	int j = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'S')
		{
			st[j].S++;
			i++;
			while (i < str.size() && str[i] == 'S')
			{
				st[j].S++;
				i++;
			}
			i--;
		}
		else
		{
			st[j].T++;
			i++;
			while (i < str.size() && str[i] == 'T')
			{
				st[j].T++;
				i++;
			}
			i--;
			j++;
		}
	}
	int ans = str.size();
	int s = 0;
	for (int i = 0; i < j; i++)
	{
		s += st[i].S;
		if (s <= st[i].T)
		{
			ans -= s * 2;
			s = 0;
		}
		else
		{
			ans -= st[i].T * 2;
			s -= st[i].T;
		}
	}
	cout << ans;
}