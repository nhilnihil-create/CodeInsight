#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	string f, s, t;
	cin >> f >> s >> t;

	cout << char(f[0] - 32) << char(s[0] - 32) << char(t[0] - 32);
}