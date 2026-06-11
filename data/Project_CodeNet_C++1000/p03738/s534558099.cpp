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
	string a, b;
	cin >> a >> b;
	if (a.length() > b.length())      cout << "GREATER" << endl;
	else if (a.length() < b.length()) cout << "LESS" << endl;
	else if (a > b)                   cout << "GREATER" << endl;
	else if (a < b)                   cout << "LESS" << endl;
	else                              cout << "EQUAL" << endl;
}