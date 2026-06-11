#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
	long long n, m;
	cin >> n >> m;
	long long ans = 0;
	if(n * 2 < m){
		ans += n;
		m -= n * 2;
		ans += m / 4;
	}
	else if(n < m){
		ans = m / 2;
	}
	else{
		ans = m / 2;
	}
	cout << ans << endl;
	return 0;
}

