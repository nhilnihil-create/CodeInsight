#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<functional>
#include <tuple>
#include <map>
#include<set>
#include <cmath>
#include <stack>
#include<cstdio>
#include<stdio.h>
using namespace std;

int main() {
	int a, b;
	string ans;
	cin >> a >> b;
	if (a > 0)ans = "Positive";
	else if (b < 0) {
		if ((abs(b - a) + 1) % 2 == 0)ans = "Positive";
		else ans = "Negative";
	}
	else ans = "Zero";
	cout << ans << endl;
}