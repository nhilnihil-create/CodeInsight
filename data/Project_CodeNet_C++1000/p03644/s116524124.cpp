#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 110;
int n, a[N];

int main() {
	
	cin >> n;
	int num = log(n) / log(2);
	cout << pow(2, num) << endl;
	return 0;
} 