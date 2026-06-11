#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#include <list>

using namespace std;



int main() {
	int n, a[100000];
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 1) {
			count++;
		}
	}
	if (count % 2 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;


	return 0;
}

