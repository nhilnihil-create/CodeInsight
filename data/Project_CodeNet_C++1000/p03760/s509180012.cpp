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
	string o, e;
	cin >> o >> e;

	rep(i, o.length())
	{
		cout << o[i];
		if (i < e.length()) cout << e[i];
	}

	return 0;
}