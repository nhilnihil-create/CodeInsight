#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	string s; cin >> s;
	int g = 0, p = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p') p++;
	}
	cout << s.size() / 2 - p << endl;
}
