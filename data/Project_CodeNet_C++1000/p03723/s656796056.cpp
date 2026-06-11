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
	int a, b, c, cnt=0;
	cin >> a >> b >> c;
	while (a%2==0&&b%2==0&&c%2==0) {
		if (a == b && a== c) { cnt = -1;break; }
		int d = a, e = b, f = c;
		a = e / 2 + f / 2;
		b = d / 2 + f / 2;
		c = d / 2 + e / 2;
		cnt += 1;
	}
	cout << cnt << endl;
}