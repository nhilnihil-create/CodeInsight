#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i< n;i++){
		cin >> v[i];
	}
	int count = 0;
	for(int i = 0;i < n;i++){
		int other = v[i];
		if (v[other-1]-1 == i) count ++ ;
	}
	cout << count/2;
}
