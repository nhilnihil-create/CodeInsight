#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
	long long n, a, b;
	cin >> n >> a >> b;
	vector<long long> x(n);
	for(long long i = 0; i < n; i++){
		cin >> x.at(i);
	}
	long long ans = 0;
	for(long long i = 1; i < n; i++){
		ans += min((x.at(i) - x.at(i - 1)) * a, b);	
	}
	cout << ans<< endl;

	return 0;
}

