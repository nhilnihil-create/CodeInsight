#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	if(n <= 2){
		cout << 1 << endl;
		return 0;
	}
	vector<lli> a(n);
	rep(i, n) cin >> a[i];

	lli ans = 0;
	for(int i = 0; i < n; i++){
		while(i+1 < n && a[i] == a[i+1])i++;
		if(i+1 < n && a[i] < a[i+1]) while(i+1 < n && a[i] <= a[i+1])i++;
		else if(i+1 < n && a[i] > a[i+1]) while(i+1 < n && a[i] >= a[i+1])i++;
		ans++;
	}
	cout << ans << endl;
	return 0;
}
