#include <iostream>
#include <cmath>
using namespace std;

void solve(long long even , long long odd , long long p , long long n){
	long long ans = 0; 
	if(even == n){
		if(p == 0){
			ans = pow(2 , n);
		}
		else if(p == 1){
			ans = 0;
		}
	}
	else{
		ans = pow(2 , n-1);
	}
	cout << ans << endl; 
}

int main(){
	long long n , p; 
	cin >> n >> p;

	long long num;
	long long even = 0; 
	long long odd = 0; 
	for(long long i = 0; i < n; i++){
		cin >> num;
		if(num % 2 == 0){
			even++;
		}
		else{
			odd++;
		}
	}
	solve(even , odd , p , n);
}