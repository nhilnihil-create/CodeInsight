#include <bits/stdc++.h>
using namespace std;
int n , x[200000] , pos , ans , now;
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
	}
	now = 0;
	for(int i = 2 ; i <= n ; i++){
		if(now == 0){
			if(x[i] == x[i - 1])now = 0;
			if(x[i] > x[i - 1])now = 1;
			if(x[i] < x[i - 1])now = 2;
		}
		else if(now == 1){
			if(x[i] < x[i - 1]){
				now = 0;
				ans++;
			}
		}
		else if(now == 2){
			if(x[i] > x[i - 1]){
				now = 0;
				ans++;
			}
		}
	}
	cout << ans + 1 << endl;
}