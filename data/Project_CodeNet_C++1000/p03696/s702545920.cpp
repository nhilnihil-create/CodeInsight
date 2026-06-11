#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	int L = 0, R = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == '(') L++;
		else if (s[i] == ')') {
			if (L > 0) L--;
			else R++;
		}
	}
	int cnt = 0;
	for (int i = 0; i < R; i++) cout << '(';	
		cout << s;
	for (int i = 0; i < L; i++) cout << ')';
}
