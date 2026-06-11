#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	string in[100];
	for (int i = 0; i < h; ++i)
	{
		cin >> in[i];
	}
	for (int i = 0; i < h * 2; ++i)
	{
		cout << in[i/2] << endl;
	}
	return 0;
}