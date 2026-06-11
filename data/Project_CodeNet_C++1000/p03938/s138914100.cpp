#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[20001], ans2[20001];

int main(){
	int n;
	cin >> n;
	for (int i=1; i<=n; i++){
		ans[i]=i*50000, ans2[i]=(n-i)*50000;
	}
	int x;
	for (int i=1; i<=n; i++){
		cin >> x;
		ans2[x]+=i;
	}
	for (int i=1; i<n; i++) cout << ans[i] << " ";
	cout << ans[n] << "\n";
	for (int i=1; i<n; i++) cout << ans2[i] << " ";
	cout << ans2[n] << "\n";
}