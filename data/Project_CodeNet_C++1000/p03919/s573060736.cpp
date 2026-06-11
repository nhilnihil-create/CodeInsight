#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int h, w;
	
	cin >> h >> w;
	
	string str[26][26];
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> str[i][j];
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (str[i][j] == "snuke") {
				printf("%c%d\n", 'A' + j, i + 1);
				break;
			}
		}
	}
	
	return (0);
}