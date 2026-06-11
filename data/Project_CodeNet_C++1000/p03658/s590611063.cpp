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
	int n,k;

	cin >> n>>k;
	
	int count = 0;
	
	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end(), greater<int>());

	for (int i = 0; i < k; i++) count = count + arr[i];

	cout << count << endl;

	return 0;

}