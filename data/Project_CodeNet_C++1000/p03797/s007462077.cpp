#include<bits/stdc++.h>

using namespace std;

long long n, m, ans;

int main(){
	cin >> n >> m;
	if(n <= m/2){
		ans += n;
		m -= n * 2;
		n = 0;
	}else{
		ans += m/2;
		m = 0;
		n -= m/2;
	}
	ans += m/4;
	cout << ans << endl;
}