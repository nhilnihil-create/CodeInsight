#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
int lst[Max], ls[Max];

int main()
{
	string str;
	cin >> str;
	int l = Max, r = -1;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == 'A')l = min(l, i);
		if (str[i] == 'Z')r = max(r, i);
	}
	if (l == Max || r == -1)cout << 0;
	else 
	cout << r - l + 1;
}