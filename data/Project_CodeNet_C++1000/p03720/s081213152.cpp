#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

#include <climits>

using namespace std;


int main(){
	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	vector<int> b(m);
	vector<int> c(n+1);

	for (int i = 0; i < m; i ++) cin >> a[i] >> b[i];
	
	for (int i = 0; i < m; i++) {
		c[a[i]]++;
		c[b[i]]++;
	}

	for (int i = 1; i <= n; i++)cout << c[i] << endl;

	return 0;
}