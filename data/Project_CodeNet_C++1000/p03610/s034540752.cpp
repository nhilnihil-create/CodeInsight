#include<iostream>
#include<stack>
#include<string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#define fast(); ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, n) for(int i= 0; i < n; ++i)
using namespace std;

int gcd(int a, int b) {
	if (a == 0)return b;
	return gcd(b % a, a);
}


int main() {
	fast();


	string s; cin >> s;
	for (int i =0 ; i < s.size(); i += 2) {
		cout << s[i];
	}

	return 0;
}
