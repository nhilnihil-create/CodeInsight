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
	int start = -1, end = -1;
	string s;
	cin >> s;
	rep(i, s.length())
	{
		if (start == -1 && s[i] == 'A') start = i;
		if (s[i] == 'Z')                end   = i;
	}
	cout << end - start + 1;
	return 0;
}