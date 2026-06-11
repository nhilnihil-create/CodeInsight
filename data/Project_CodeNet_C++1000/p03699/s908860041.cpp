#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[100], ans, idx;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		ans += a[i];
	}

	sort(a, a+n);

	while(ans%10==0){
		if(a[idx]%10==0){
			idx++;
		}
		else{
			ans -= a[idx];
			break;
		}
		
		if(idx==n){
			ans = 0;
			break;
		}
	}

	cout << ans << endl;
}