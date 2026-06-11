#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, k;

int main(void){
	cin >> n >> k;
	lli ans = k;
	n--;
	while(n--) ans*=k-1;
	cout << ans << endl;
	return 0;
}
