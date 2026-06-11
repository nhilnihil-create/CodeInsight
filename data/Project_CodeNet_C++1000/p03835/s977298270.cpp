#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli k, s;

int main(void){
	cin >> k >> s;
	lli ans = 0;
	for(lli i = 0; i <= k; i++){
		for(lli j = 0; j <= k; j++){
			lli u = s-i-j;
			if(u >= 0 && u <= k) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
