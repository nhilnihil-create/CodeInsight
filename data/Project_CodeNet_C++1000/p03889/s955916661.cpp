#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	string x, y;
	cin >> x;
	y = x;
	reverse(y.begin(), y.end());
	for(int i = 0;y[i];i++)
	{
		if(y[i] == 'b') y[i] = 'd';
		else if(y[i] == 'd') y[i] = 'b';
		else if(y[i] == 'p') y[i] = 'q';
		else if(y[i] == 'q') y[i] = 'p';
	}
	if(y == x) puts("Yes");
	else puts("No");
	return 0;
}