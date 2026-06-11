#include <iostream>
#include <algorithm>
#include <array>
#include <math.h>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>

#define INT_MAX 2000000000
#define MOD 1000000007
#define ll long long
#define rep(i,a,b) for(i = (a); i < (b); i++)
#define bitget(a,b) (((a) >> (b)) & 1)

using namespace std;

int i, j, k;

int main() {
	ll int k;
	cin >> k;
	ll int a[50];
	rep(i, 0, 50) {
		a[i] = k / 50 + 50;
	}
	int b;
	b = 50 - k % 50;
	rep(i, 0, k % 50) {
		a[i] += b;
	}
	rep(i, k%50, 50) {
		a[i] = a[i] - 50 + b - 1;;
	}
	cout << "50" << endl;
	rep(i, 0, 50) {
		cout << a[i];
		if (i != 49)
			cout << " ";
	}
	cout << endl;
	return 0;
}