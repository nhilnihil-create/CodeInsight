#include <iostream>
using namespace std;

int main(){
	int n, p;
	cin >> n;
	for(int i = 1, sum = 0; i <= n; i++){
		sum += i;
		if(sum >= n){
			p = i;
			break;
		}
	}
	for(int i = p; i > 0; i--){
		if(n == 0) break;
		if(n - i >= 0){
			n -= i;
			cout << i << endl;
		}
	}
}