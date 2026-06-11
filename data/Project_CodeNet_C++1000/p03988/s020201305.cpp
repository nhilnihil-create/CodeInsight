#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],dp[100005];
main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	int mx = 0,mn = INT_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];  
		b[a[i]]++;
		mx = max(mx,a[i]);
		mn = min(mn,a[i]);
	}
	if (mn != (mx+1)/2)
	{
		cout << "Impossible";
		return 0;
	}
	int y = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == mn){
			y++;
		}
	}
	if (((mx%2 == 1) && y != 2) || (mx %2 == 0 && y != 1)){
		cout << "Impossible";
		return 0;
	}
	for (int i = mn+1; i <= mx; i++){
		if(b[i] <= 1)
		{
			cout << "Impossible";
			return 0;
		} 	
	}
	cout << "Possible";
		
}