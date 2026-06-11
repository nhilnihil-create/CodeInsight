#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
#include <stdio.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)
#pragma GCC optimize("Ofast")



int main() {
	int n;
	cin >> n;
	if (n >= 64)cout << 64 << endl;
	else if (n >= 32)cout << 32 << endl;
	else if (n >= 16)cout << 16 << endl;
	else if (n >= 8)cout << 8 << endl;
	else if (n >= 4)cout << 4 << endl;
	else if (n >= 2)cout << 2 << endl;
	else cout << 1 << endl;
	return 0;
}
