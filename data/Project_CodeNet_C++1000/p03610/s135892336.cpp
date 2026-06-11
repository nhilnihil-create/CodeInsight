#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (i % 2 == 0) printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}
