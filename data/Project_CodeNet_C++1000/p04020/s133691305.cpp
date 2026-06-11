#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long LL;

int n;
LL a[N], ans;

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i < n; i++) {
		ans += a[i]/2;
		if(a[i]%2 && a[i + 1]) a[i + 1]--, ans++; 
	}
	ans += a[n]/2;
	cout<<ans<<endl;

	return 0;
}