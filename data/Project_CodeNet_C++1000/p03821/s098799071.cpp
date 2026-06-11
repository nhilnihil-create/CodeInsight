#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> a(n+1), b(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	lli c = 0;
	for(int i = n; i >= 1; i--){
		c+=(b[i]-(a[i]+c)%b[i])%b[i];
	}
	cout << c << endl;
	return 0;
}
