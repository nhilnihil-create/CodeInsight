#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	string s, str;
	cin >> s;

	int len = s.length();
	str = s[0] + to_string(len-2) + s[len - 1];
	cout << str << endl;

	return 0;
}