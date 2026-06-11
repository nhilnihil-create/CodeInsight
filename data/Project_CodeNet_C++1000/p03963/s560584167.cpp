#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	long n,k,a;
	cin>>n>>k;

     a=k*pow(k-1,n-1);
	cout<<a;
	return 0;
}