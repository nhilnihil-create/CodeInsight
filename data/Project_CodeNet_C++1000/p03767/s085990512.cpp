#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >>n;
	long n3= n*3;
	vector<int> a(n3);
	for(auto& x:a){
		cin >> x;
	}
	sort(a.begin(), a.end());
	long sum = 0;

	for(int i =0; i<(n*2); i += 2){
		sum += a.at(n+i);
	}
	cout << sum << endl;
}
