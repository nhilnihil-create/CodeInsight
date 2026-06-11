#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	int sum=0;
	cin >> n >> k;
	vector<int> vec(n);
	for(int i=0; i<n; i++){
		cin >> vec.at(i);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for(int i=0; i<k; i++){
		sum += vec.at(i);
	}
	cout << sum << endl;
}
