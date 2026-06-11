#include<iostream>
#include<math.h>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
	
	ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	if ((b - a) == (c - b))cout << "YES";
	else cout << "NO";
	return 0;
}