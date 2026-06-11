#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 123;
int n, a[N], mx = 0, mn = 1e5 + 123, kol[N];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		kol[a[i]]++;
	}
	if(mx - mn >= 2){
		cout << "No";
		exit(0);
	}
	if(mx - mn == 0){
		if(mn <= n / 2 || mn == n - 1) cout << "Yes";
		else cout << "No";
		exit(0);
	}
	else{
		if(kol[mn] <= mn && kol[mn] >= mn - (n - (mn + 2))){
			cout << "Yes";
			exit(0);
		} 
		else cout << "No";
	}
}