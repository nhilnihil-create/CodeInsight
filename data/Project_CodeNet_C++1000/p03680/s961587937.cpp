#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0;i<n;++i)cin >> arr[i];
	int vis[n];
	memset(vis, 0, sizeof(vis));
	int temp = arr[0];
	int steps = 1, c= 1;
	while(temp != 2){
		if(vis[temp - 1] == 0){
			steps++;
			vis[temp - 1]++;
			temp = arr[temp - 1];	
		}
		else {
			c = 0;
			break;
		}
	}
	(c == 1)?cout << steps:cout << -1;
}


