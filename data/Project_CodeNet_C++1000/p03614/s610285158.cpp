#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a, cnt = 0;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a;
		if(a == i){
			cnt++;
			cin >> a;
			i++;
		}
	}
	cout << cnt;
}
