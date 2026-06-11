#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include <algorithm>
#include<math.h>
#include<set>
#include<map>
#include <sstream>
#include<iomanip>
#include <ctype.h>
using namespace std;

//#include<bits/stdc++.h>


int main() {
	
	int h, w;
	cin >> h >> w;
	
	for (int i = 0; i < h; i++) {
		char g = 'A';
		for (int j = 0; j < w; j++) {
			string p;
			cin >> p;
			if (p == "snuke") {
				cout << g  << i + 1 << endl;
				return 0;
			}
			g++;
		}
	}
	return 0;
}