#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

#define REP(i, n) for(int i = 0; i != n; ++i)
#define REPR(i, n) for(int i = n - 1; i != -1; --i)
#define FOR(i, a, b) for(int i = a; i != b; ++i)
#define IN(n) (cin >> n)
#define OUT(n) (cout << n << endl)

using namespace std;
using ll = unsigned long long;


int main() {
	string S;
	cin >> S;
	string s = "CODEFESTIVAL2016";
	int i, count = 0;
	for(i = 0; i < 16; i++) {
		if(S[i] != s[i]) count++;
	}
	cout << count << endl;
}
