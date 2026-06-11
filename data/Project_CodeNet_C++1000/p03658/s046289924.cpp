#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> l(n);
	for(auto& x:l){
		cin >> x;
	}
	sort(l.begin(), l.end());
	int sum = 0;
	for(int i = n-1; i>=(n-k); i--){
		sum += l.at(i);
	}
	cout << sum << endl;
}
