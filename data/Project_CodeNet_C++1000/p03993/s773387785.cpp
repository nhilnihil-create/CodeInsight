#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main()
{		
	map< int, int > mp;
	int n;
	cin >> n;
	int cnt=0;
	int arr[n+1];
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		mp[i] = arr[i];
	}
	for(int i=1; i<=n; i++) {
	 	if(mp[arr[i]]==i) cnt++;	
	}
	cout << cnt/2 << endl;
	return 0;
}