#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <utility>
#include <algorithm>

#define rep(i,p,n) for(int i=p;i<n;i++)
#define lli long long int
#define vi vector<int> 

using namespace std;

void p(int x) {
	cout << x << endl;
}

void pp(string s) {
	cout << s << endl;
}


int main() {
	int n, m;
	cin >> n >> m;

	rep(i, 0, n) {
		rep(j, 0, m) {
			string s;
			cin >> s;
			if (s == "snuke") {
				cout << (char)('A' + j) << i+1 << endl;
			}
		}
	}



	return 0;
}