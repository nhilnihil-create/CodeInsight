#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<stdlib.h>
#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007

using namespace std;


int main(void) {
	string s, t;
	int p;
	cin >> s;
	p = s.size() - 1;
	RFOR(i, p, 0) {
		t.push_back(s[i]);
	}
	FOR(i, 0, p) {
		if (t[i] == 'd') {
			t[i] = 'b';
		}
		else if (t[i] == 'b') {
			t[i] = 'd';
		}
		else if (t[i] == 'p') {
			t[i] = 'q';
		}
		else if (t[i] == 'q') {
			t[i] = 'p';
		}
	}
	if (s == t) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}