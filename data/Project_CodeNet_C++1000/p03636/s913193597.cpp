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
	cout << str[0] << str.size() - 2 << str[str.size() - 1];
}