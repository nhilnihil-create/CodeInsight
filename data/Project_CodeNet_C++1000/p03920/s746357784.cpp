#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::cin;

int main(){
	int n; cin >> n;
	
	int pos = 0, pot;
	for(int i = 1; i <= n; i++){
		pos += i;
		
		if(pos > n){
			pot = pos - n;
			break;
		}
	}
	
	pos = 0;
	for(int i = 1; pos < n; i++){
		if(i == pot) continue;
		pos += i;
		
		cout << i << endl;
	}
	
	return 0;
}
