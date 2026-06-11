#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	vector<string> s(a);
	for (int i = 0; i < a; i++) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	for (int i = 0; i < a; i++) {
		cout << s[i];
	}
}