//arc078_c.cpp
//Fri Jun  8 22:21:25 2018

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main(){
	int n;
	cin >> n;

	int a[n];
	ll sum = 0;
	for (int i=0;i<n;i++){
		cin >> a[i];
		sum = sum + a[i];
	}

	ll ssum = a[0];
	sum = sum - a[0];
	ll ans = abs(sum-ssum);

	for (int i=1;i<n-1;i++){
		ssum = ssum + a[i];
		sum = sum - a[i];
		ll temp = abs(sum-ssum);
		if (temp < ans){
			ans = temp;
		}
	}

	cout << ans << endl;
}