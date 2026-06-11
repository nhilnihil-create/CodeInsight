#include <bits/stdc++.h>
using namespace std;
int n;
long long a[305][305];
long long ans = 0;
 
int main()
{
	cin>>n;
	for (int i=1;i<=n; i++){
		for (int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
		
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++) {
			int k;
			for (k=1;k<=n;k++) {
				if (i==k||j == k) continue;
				if(a[i][k]+a[k][j]<a[i][j]){
					cout<<"-1"<<endl;
					return 0;
				}
				if(a[i][k]+a[k][j]==a[i][j]){
					break;
				}
			}
			if (k==n+1) {
				ans += a[i][j];
			}
		}
	cout<<ans<<endl;
 
	return 0;
}