#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string sr = s;
	reverse(sr.begin(), sr.end());
	cout << (s.size() - sr.find('Z')) - s.find('A') << endl;
	return 0;
}