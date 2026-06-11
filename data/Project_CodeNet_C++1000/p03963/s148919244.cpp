#include <iostream>
#include <math.h>
using namespace std;
int main(void){
	long long  n,k,result;
	cin >>n >> k;
	result = k*pow(k-1,n-1);
	cout << result << endl;
}
