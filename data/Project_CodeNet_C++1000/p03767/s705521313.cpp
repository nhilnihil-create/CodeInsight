#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(3*n);
	for (int i=0; i<3*n; i++){
		cin >> v[i];
	}
	long long sum=0;
	sort(v.rbegin(), v.rend());
	for(int i = 1; i<2*n; i+=2){
		sum+=v[i];
	}
	cout << sum;
 }
