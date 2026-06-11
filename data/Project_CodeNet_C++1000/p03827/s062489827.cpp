#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max], ls[Max];

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int ma = 0;
	int x = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'D')x--;
		else x++;
		ma = max(ma, x);
	}
	cout << ma;
}