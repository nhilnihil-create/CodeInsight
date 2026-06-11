#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	long long n;
	cin >> n;

	vector<long long> a(n, 0);
	long long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	long long p_sum = 0;
	long long abs_min = abs(2 * a[0] - sum);
	for(int i = 0; i < n - 1; i++){
		p_sum += a[i];
		if(abs(2 * p_sum - sum) < abs_min){
			abs_min = abs(2 * p_sum - sum);
		}
	}

	cout << abs_min << endl;

	return 0;
}