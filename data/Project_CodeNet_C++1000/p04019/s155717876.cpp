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
	string s;
	cin >> s;
	if ((s.find("N") != -1 && s.find("S") == -1) ||
		(s.find("S") != -1 && s.find("N") == -1) ||
		(s.find("W") != -1 && s.find("E") == -1) ||
		(s.find("E") != -1 && s.find("W") == -1))
		 cout << "No";
	else cout << "Yes";
	return 0;
}