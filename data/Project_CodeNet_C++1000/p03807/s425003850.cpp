#include <iostream>
using namespace std;

void findTheAns(long long odd){
	if(odd % 2 == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main() {
	long long n , num;
	cin >> n;
	
	long long odd = 0;
	for(long long i = 0; i < n; i++){
		cin >> num;
		if(num % 2 == 1){
			odd++;
		}
	}
	findTheAns(odd);
}