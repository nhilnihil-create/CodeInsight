#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<cctype>
using namespace std;


int main() {
	int w, h;
	int a = 0;
	char b = 'A';
	string s[26][26];
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> s[i][j];
			if (s[i][j] == "snuke") {
				a = i + 1;
				b += j;
			}
		}
	}
	cout << b << a << endl;
}