#include<iostream>
using namespace std;

int a[11]; 
bool f(int n){
	while(n > 0){
		if(a[n%10] == 1){
			return false;
		}
		n /= 10;
	}
	return true;
}

int main(){
	int n, k, tmp;
	cin >> n >> k;
	for(int i = 1; i<= k; i++){
		cin >> tmp;
		a[tmp] = 1;
	}
	
	while(true){
		if(!f(n))
			n++;
		else{
			cout << n; 
			break;
		}
	}
	
	return 0;
}