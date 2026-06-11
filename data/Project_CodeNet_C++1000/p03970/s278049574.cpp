#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int ans = 0;
	string S;
	cin >> S;
	string temp = "CODEFESTIVAL2016";
	for (int i = 0; i < S.size(); i++) {
		if (S[i] != temp[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
