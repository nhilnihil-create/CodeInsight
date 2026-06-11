#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[2005];
	cin >> n;
	for (int i=1;i<=2*n;i++) cin >> a[i];
	sort(a+1,a+1+2*n);
	int ans=0;
	for (int i=1;i<=2*n;i+=2) ans+=a[i];
	cout << ans << endl;
}