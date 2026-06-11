#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<limits>
#include<ctime>
#include<stack>
#include<bits/stdc++.h>
#define long long
using namespace std;

int main(){
	long a, b;
	cin >> a >> b;
	if (a * b <= 0) {
		cout << "Zero" << endl;
		return 0;
	}
	if (b < 0) {
		int minus = (b - a + 1) % 2;
		if (minus) {
			cout << "Negative" << endl;
			return 0;
		}
	}
	cout << "Positive" << endl;
	return 0;
 
	return 0;
}
