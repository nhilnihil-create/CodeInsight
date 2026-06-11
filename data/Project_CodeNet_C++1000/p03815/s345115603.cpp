#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
	long long x;
	cin >> x;
	long long ans = (x / 11) * 2;
	x %= 11;
	if(x > 6){
		ans += 2;
	}
	else if(x > 0){
		ans += 1;
	}
	cout << ans << endl;
	return 0;
}

