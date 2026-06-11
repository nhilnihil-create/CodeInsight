#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	printf(S.substr(0, 4) == "YAKI" ? "Yes\n" : "No\n");
	return 0;
}
