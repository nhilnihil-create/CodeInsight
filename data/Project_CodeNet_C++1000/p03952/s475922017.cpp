#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, k;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	if( k == 1 || k == (2*n - 1))
		cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		int cur = 1;
		for(int i = 0; i < n - 2;  i ++){
			if( cur == k - 1) cur = k + 2;
			cout << cur << endl;
			cur ++;
		}
		cout << k - 1 << endl << k << endl << k + 1 << endl;
		for(int i = 0; i < n - 2; i ++){
			if( cur == k - 1) cur = k + 2;
			cout << cur << endl;
			cur ++;
		}
	}
	return 0;
}
