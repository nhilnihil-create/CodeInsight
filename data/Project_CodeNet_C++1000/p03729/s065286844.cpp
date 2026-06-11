#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string s[3];
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
	}
	if (s[0][s[0].length() - 1] == s[1][0] && s[1][s[1].length() - 1] == s[2][0]) printf("YES\n");
	else printf("NO\n");


	return 0;
}
