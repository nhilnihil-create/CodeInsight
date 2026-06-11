#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	string s[26][26];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == "snuke") {
				printf("%c%d", 'A' + j, i + 1);
			}
		}
	}
}