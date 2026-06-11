#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	int i = 1;
	while (1) {
		string cutted = S.substr(0, S.size() - i);
		i++;
		if (cutted.size() % 2 != 0) continue;
		bool even = true;
		for (int j = 0; j < cutted.size() / 2; j++) {
			if (cutted[j] != cutted[cutted.size() / 2 + j]) even = false;
		}
		if (even) {
			printf("%d\n", cutted.size());
			return 0;
		}
	}
	return 0;
}
