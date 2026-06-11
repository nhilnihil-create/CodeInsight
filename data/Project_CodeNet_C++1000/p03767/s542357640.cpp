
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
	int n;
	
	cin >> n;

	vector<long long> arr(3*n);
	
	for (int i = 0; i < 3 * n; i++) cin>>arr[i];

	sort(arr.begin(), arr.end(), greater<long long>());

	int i = 1;
	long long sum = 0;
	while (i<=n) {
		int m = 2 * i - 1;
		sum = sum + arr[m];
		i++;
	}
	cout << sum << endl;

	return 0;
}