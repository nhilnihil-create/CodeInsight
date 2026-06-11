#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int pos;
	cin >> pos;
	
	int sum = 0;
	
	for(int i = 1 ; ; i ++){
		sum += i;
		if(sum >= pos){
			cout << i << "\n";
			return 0;
		}
	}
	
	return 0;
}