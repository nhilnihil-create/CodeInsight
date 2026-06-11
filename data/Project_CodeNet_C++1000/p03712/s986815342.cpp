#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long int ll;


int main()
{
	int h, w;
	cin >> h >> w;
	vector<vector<char>> charList(h);
	for (int i = 0; i < h; i++) {
		charList[i] = vector<char>(w);
		for (int j = 0; j < w; j++) {
			cin >> charList[i][j];
		}
	}
	for (int i = 0; i < w+2; i++) {
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < h; i++) {
		cout << "#";
		for (int j = 0; j < w; j++) {
			cout << charList[i][j];
		}
		cout << "#" << endl;
	}

	for (int i = 0; i < w+2; i++) {
		cout << "#";
	}
	cout << endl;
	return 0;
}