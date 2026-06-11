#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<memory.h>
using namespace std;
typedef long long ll;
const int Max = 4e5 + 5;

int lst[Max];

int main()
{
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	string str;
	int dx = tx - sx, dy = ty - sy;
	for (int i = 1;i <= dx;i++)
	{
		str += "R";
	}
	for (int i = 1;i <= dy;i++)
	{
		str += "U";
	}
	for (int i = 1;i <= dx;i++)
	{
		str += "L";
	}
	for (int i = 1;i <= dy;i++)
	{
		str += "D";
	}
	str += "L";
	for (int i = 1;i <= dy+1;i++)
	{
		str += "U";
	}
	for (int i = 1;i <= dx+1;i++)
	{
		str += "R";
	}
	str += "DR";
	for (int i = 1;i <= dy+1;i++)
	{
		str += "D";
	}
	for (int i = 1;i <= dx+1;i++)
	{
		str += "L";
	}
	str += "U";
	cout << str;
}