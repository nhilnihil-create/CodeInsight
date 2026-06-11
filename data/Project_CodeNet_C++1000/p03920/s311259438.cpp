#define _USE_MATH_DEFINES
#include  <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include <queue>
#include<map>
#include <sstream>
#include<set>
#include<stack>

//#include<bits/stdc++.h>


using namespace std;



int main() {

	int r = 0;
	int x = 0;
	int z = 0;
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		x += i;
		z = i;
		if (x >= n)break;
	}
	r = x - n;
	for (int i = 1; i <= z; i++) {
		if (r == i)continue;
		cout << i << endl;
	}

	return 0;


}