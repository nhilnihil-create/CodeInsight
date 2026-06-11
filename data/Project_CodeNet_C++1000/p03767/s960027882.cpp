#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int m = 3*n;
	vector<long> a(m);
	for (int i=0; i<m; i++){
	       cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	long sum = 0;
	for(int i=n; i<m; i+=2){
		sum += a.at(i);
	}
	cout << sum << endl;
}	
