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
	map<char, bool> check;
	string s;
	cin >> s;

	rep(i, s.length())
	{
		if (check[s[i]] != true) check[s[i]] = true;	//未登録のアルファベットだったら追加
		else
		{
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
}