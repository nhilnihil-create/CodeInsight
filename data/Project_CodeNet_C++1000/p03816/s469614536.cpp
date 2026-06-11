#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());
	int b = a.at(0);
	int cnt = 0;
	for(int i = 1; i < n; i++){
		if(a.at(i) == b){
			cnt += 1;
		}
		else{
			b = a.at(i);
		}
	}
	// cout << "b : " << b << endl;
	// cout << "cnt : " << cnt << endl;
	if(cnt % 2 == 0){
		cout << n - cnt << endl;
	}
	else{
		cout << n - cnt - 1 << endl;
	}
	return 0;
}

