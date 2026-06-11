#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 7;
int lst[Max];

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i <= str.size() - 1; i++) lst[str[i] - 'a']++;
	int f = 1;
	for (int i = 0; i <= 25; i++)
	{
		if (lst[i] == 0) { cout << char('a' + i); f = 0; break; }
	}
	if (f)cout << "None";
}