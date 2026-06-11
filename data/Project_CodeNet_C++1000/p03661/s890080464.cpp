#include "bits/stdc++.h"
#define rep(i,a,n) for(int i = a;i < n;i++)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int main(){
	ll n,sum = 0,memo = 0,ans = 10000000000;
	cin >> n;
	ll a[n];
	
	rep(i,0,n){
		cin >> a[i];
		sum += a[i];
	}
	
	
	
	rep(i,0,n-1){
		memo += a[i];
		ans = min(abs((sum-memo)-memo),ans);
	}
	
	cout << ans << endl;
	return 0;
}