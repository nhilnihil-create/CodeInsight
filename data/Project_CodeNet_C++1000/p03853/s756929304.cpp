#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 5;
char lst[Max][Max];

int main()
{
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			char c;
			scanf(" %c", &lst[i][j]);
		}
	}
	for (int i = 1; i <= 2 * x; i++)
	{
		int xx;
		if (double(i + 1) / 2 > (double)(i + 1) / 2 + 0.5)xx = ceil((i + 1) / 2);
		else xx = (i + 1) / 2;
		for (int j = 1; j <= y; j++)
		{
			printf("%c", lst[xx][j]);
		}
		cout << endl;
	}
}