#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int x = 0, n, max = 0;
	string s;
	cin >> n >> s;

	rep(i, n)
	{
		if (s[i] == 'I')	x++;
		else x--;

		if (x > max) max = x;
	}

	cout << max << endl;
	return 0;
}