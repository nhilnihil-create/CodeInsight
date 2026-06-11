#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define LL long long
using namespace std;
int x, y;
int main()
{ 
	cin >> x >> y;
	if (x == y) cout << "0\n";
	else if (x < y) cout << min(y - x, abs(y + x) + 1) << '\n';
	else cout << min(abs(x + y) + 1, x - y + 2) << '\n';
}