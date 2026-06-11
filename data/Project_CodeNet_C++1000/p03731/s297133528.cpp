#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t; cin >> n >> t;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int sum = t;
	for(int i = 0; i < n - 1; i++){
		int x1 = a[i], y1 = a[i] + t;
		int x2 = a[i + 1], y2 = a[i + 1] + t;
		if(x2 < y1){
			sum += (x2 - x1);
		}
		else sum += t;
	}
	
	cout << sum;
	return 0;
}