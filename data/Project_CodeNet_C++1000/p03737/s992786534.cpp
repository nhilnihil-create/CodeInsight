#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	for (int i = 0; i < 3; i++) {
		string s;
		cin >> s;
		printf("%c", s[0] + ('A' - 'a'));
	}
	printf("\n");


	return 0;
}
