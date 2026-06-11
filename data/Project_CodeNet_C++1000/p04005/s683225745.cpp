#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long A[3];
	cin >> A[0] >> A[1] >> A[2];
	
	sort(A,A+3);
	if(A[2] % 2 == 0){
		cout << 0 ;
	}
	else cout << A[0]*A[1] ;
} 