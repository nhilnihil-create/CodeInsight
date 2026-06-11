#include <iostream>
using namespace std;
int main(){
	int k, s;
	cin >> k >> s;
	int sum = 0;
	for(int i = 0; i<= k ;i++){
		for(int j = 0; j <= k; j++){
			if(i+j <= s){
				if(s-(i+j) <= k){
					sum++;
				}
			}
		}
	}
	cout << sum;
	return 0;
} 